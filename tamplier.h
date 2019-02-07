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
        tamplier(const tamplier&);
        const tamplier& operator = (const tamplier&);
        virtual ~tamplier();

        /**
         * fill template by specified rules.
         * @param rules
         * @return filled template
         */
        tamplier fill(const vector&) const;
        /**
         * fill template by specified rules. second parameter permits to apply
         * rules consecutively more then one.
         * @param rules
         * @param depth
         * @return filled template
         */
        tamplier fill(const vector&, const size_t&) const;
        /**
         * returns generated value
         * @return generated string
         */
        string to_string() const;
    };
}

#endif /* TAMPLIER_H */

