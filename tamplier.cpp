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

    tamplier::tamplier(const tamplier& t) : _template(t._template) {

    }

    const tamplier& tamplier::operator=(const tamplier& t) {
        _template = t._template;
        return *this;
    }

    tamplier::~tamplier() {
    }

    tamplier tamplier::fill(const vector& rule) const {
        string _result = _template;
        for (pair p : rule) {
            _result = mc::replace(p.first, p.second, _result);
        }
        return tamplier(_result);
    }

    tamplier tamplier::fill(const vector& rule, const size_t& depth) const {        
        if (depth > MAX_DEPTH_PATTERN) {
            throw std::exception();
        }
        string _result = _template;
        for (size_t count = 0; count < depth; ++count) {
            string tmp = tamplier(_result).fill(rule).to_string();
            if (_result == tmp) {
                break;
            }
            _result = tmp;
        }
        return tamplier(_result);
    }


    string tamplier::to_string() const {
        return _template;
    }
}