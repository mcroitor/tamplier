#include "tamplier.h"

namespace mc {

    string replace(string from, string to, string source) {
        if (from.empty()) {
            return source;
        }
        size_t start = 0;
        auto it = source.find(from, start);
        while (it != string::npos) {
            source = source.substr(0, it) + to + source.substr(it + from.length(), string::npos);
            start = it + to.length();
            it = source.find(from, start);
        }
        return source;
    }

    tamplier::tamplier(string tpl) : _template(tpl) {

    }

    tamplier::~tamplier() {
    }

    string tamplier::fill(const map& rule) const {
        string result = _template;
        for (pair p : rule) {
            result = mc::replace(p.first, p.second, result);
        }
        return result;
    }

    string tamplier::fill(const vector& rule) const {
        string result = _template;
        for (pair p : rule) {
            result = mc::replace(p.first, p.second, result);
        }
        return result;
    }

    string tamplier::fill(const map& rule, const size_t& depth) const {
        string result = _template;
        // TODO#: if depth > MAX_DEPTH, throw exception
        for (size_t count = 0; count < depth; ++count) {
            string tmp = tamplier(result).fill(rule);
            if (result == tmp) {
                break;
            }
            result = tmp;
        }
        return result;
    }

    string tamplier::fill(const vector& rule, const size_t& depth) const {
        string result = _template;
        // TODO#: if depth > MAX_DEPTH, throw exception
        for (size_t count = 0; count < depth; ++count) {
            string tmp = tamplier(result).fill(rule);
            if (result == tmp) {
                break;
            }
            result = tmp;
        }
        return result;
    }

    string tamplier::get_template() const {
        return _template;
    }
}