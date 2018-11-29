/* 
 * File:   tamplier.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 31 iulie 2018, 14:42
 */

#ifndef TAMPLIER_H
#define TAMPLIER_H

#include <string>
#include <map>
#include <vector>

namespace mc {
    using std::string;
    using map = std::map<string, string>;
    using pair = std::pair<string, string>;
    using vector = std::vector<pair>;
    using std::size_t;
    
    const size_t MAX_DEPTH_PATTERN = 100;
    /*! \fn
     * replace all _from_ to _to_ in _source_
     * @param from 
     * @param to
     * @param source
     * @return result
     */
    string replace(string /*from*/, string /*to*/, string /*source*/);

    /*! \class
     * complete a template by defined rules
     */
    class tamplier {
        string _template;

    public:
        /**
         * set template
         * @param 
         */
        explicit tamplier(string);
        virtual ~tamplier();
        /**
         * fill template by specified rules. attention! map orders values by keys
         * alphabetically! check example!
         * @param rules
         * @return filled template
         */
        string fill(const map&) const;
                /**
         * fill template by specified rules.
         * @param rules
         * @return filled template
         */
        string fill(const vector&) const;
        /**
         * fill template by specified rules. second parameter permits to apply
         * rules consecutively more then one.
         * @param rules
         * @param depth
         * @return filled template
         */
        string fill(const map&, const size_t&) const;
        /**
         * fill template by specified rules. second parameter permits to apply
         * rules consecutively more then one.
         * @param rules
         * @param depth
         * @return filled template
         */
        string fill(const vector&, const size_t&) const;
        /**
         * return template
         * @return 
         */
        string get_template() const;
    };
}

#endif /* TAMPLIER_H */

