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

namespace mc {
    /*! \fn
     * replace all _from_ to _to_ in _source_
     * @param from 
     * @param to
     * @param source
     * @return result
     */
    std::string replace(std::string /*from*/, std::string /*to*/, std::string /*source*/);

    /*! \class
     * complete a template by defined rules
     */
    class tamplier {
        std::string _template;

    public:
        /**
         * set template
         * @param 
         */
        explicit tamplier(std::string);
        virtual ~tamplier();
        /**
         * fill template by specified rules
         * @param rules
         * @return filled template
         */
        std::string fill(const std::map<std::string, std::string>&) const;
        /**
         * return template
         * @return 
         */
        std::string get_template() const;
    };
}

#endif /* TAMPLIER_H */

