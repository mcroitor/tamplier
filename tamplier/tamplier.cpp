#include "tamplier.h"

namespace mc{
    
    std::string replace(std::string from, std::string to, std::string source){
        if(from.empty()){
            return source;
        }
        size_t start = 0;
        auto it = source.find(from, start);
        while(it != std::string::npos ){
            source = source.substr(0, it) + to + source.substr(it + from.length(), std::string::npos);
            start = it + to.length();
            it = source.find(from, start);
        }
        return source;
    }

    tamplier::tamplier(std::string tpl): _template(tpl) {

    }
    tamplier::~tamplier(){}

    std::string tamplier::fill(const std::map<std::string,std::string>& rule) const{
        std::string result = _template;
        for(std::pair<std::string, std::string> pair: rule){
            result = mc::replace(pair.first, pair.second, result);
        }
        return result;
    }
    
    std::string tamplier::get_template() const{
        return _template;
    }
}