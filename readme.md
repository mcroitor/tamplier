# Tamplier - simple library for fill templates

## Description

The _Tamplier Library_ solves most common of filling templates with values by
defined rules.

## Example

```C++
const std::string tpl = "<html>"
            "<head>"
            "<title><!-- title --></title>"
            "</head>"
            "<body>"
            "<!-- body -->"
            "</body>"
            "</html>";

const mc::vector& rules = {
    {"<!-- title -->", "this is a title"},
    {"<!-- body -->", "this is a body content"}
};

mc::tamplier _tamplier(tpl);
std::string result = _tamplier.fill(rules).to_string();
```

## Interface

```C++
namespace mc {
    using std::string;
    using pair = std::pair<string, string>;
    using vector = std::vector<pair>;
    using std::size_t;
    
    const size_t MAX_DEPTH_PATTERN = 100;

    string replace(string /*from*/, string /*to*/, string /*source*/);

    class tamplier {
        explicit tamplier(string /* template */);
        tamplier(const tamplier& /* template */);
        const tamplier& operator =(const tamplier& /* template */);
        virtual ~tamplier();

        tamplier fill(const vector& /* vector_of_rules */) const;
        tamplier fill(const vector& /* vector_of_rules */, const size_t& /* nr_iterations */) const;
        string to_string() const;
    };
}
```