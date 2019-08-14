# Cyanide

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

[![Build Status](https://travis-ci.com/styinx/Cyanide.svg?branch=dev)](https://travis-ci.com/styinx/Cyanide)
[![Coverage Status](https://coveralls.io/repos/github/styinx/Cyanide/badge.svg?branch=dev)](https://coveralls.io/github/styinx/Cyanide?branch=dev)

[![Build Status](https://travis-ci.com/styinx/Cyanide.svg?branch=master)](https://travis-ci.com/styinx/Cyanide)
[![Coverage Status](https://coveralls.io/repos/github/styinx/Cyanide/badge.svg?branch=master)](https://coveralls.io/github/styinx/Cyanide?branch=master)

## blub

## Styleguide

### Formatting

<table style="width:100%;">
  <tbody>
    <tr style="background: #CCCCCC">
      <th></th>
      <th></th>
      <th>Example</th>
    </tr>
    <tr tr style="background: #FFFFFF">
      <td>Header files</td>
      <td>
        <ul>
          <li>Header guard</li>
          <li>C++ headers</li>
          <li>C headers</li>
          <li>Library headers</li>
          <li>Project headers</li>
          <li>Macros</li>
          <li>Namespace</li>
          <ul>
            <li>Aliases</li>
            <li>Enums</li>
            <li>Classes</li>
          </ul>
        </ul>
      </td>
      <td>
<pre>
#ifndef HEADER_FILE_HPP
#define HEADER_FILE_HPP

#include <map>

#include <stdio.h>

#include <boost/any.hpp>

#include "foo.hpp"

namespace bar
{

    using Byte = std::uint8_t;

    enum class COLOR : Byte { };

    class Dot {};

}  // namespace bar

#endif  // HEADER_FILE_HPP
</pre>
      </td>
    </tr>
    <tr tr style="background: #FFFFFF">
      <td>Source file</td>
      <td>
        <ul>
          <li>Corresponding header file</li>
          <li>C++ headers</li>
          <li>C headers</li>
          <li>Library headers</li>
          <li>Project headers</li>
          <li>Namespace</li>
          <li>Static variables</li>
          <li>Class members</li>
        </ul>
      </td>
      <td>
<pre>
#include "foo.hpp"

#include <map>

#include <stdio.h>

#include <boost/any.hpp>

namespace bar
{
namespace foo
{
    
    ClassName::ClassName() {}

}  // namespace foo
}  // namespace bar
</pre>
      </td>
    </tr>
  </tbody>
</table>

### Naming

<table style="width:100%;">
  <tbody>
    <tr style="background: #CCCCCC">
      <th></th>
      <th></th>
      <th>Example</th>
    </tr>
    <tr tr style="background: #FFFFFF">
      <td>Namespace</td>
      <td>flatcase</td>
      <td>
<pre>
namespace mynamespace
{
    ... some code
}
</pre>
      </td>
    </tr>
    <tr tr style="background: #FFFFFF">
      <td>Classnames</td>
      <td>CamelCase</td>
      <td>
<pre>
class MyClassName
{
    ... some code
}
</pre>
      </td>
    </tr>
    <tr tr style="background: #FFFFFF">
      <td>Variables</td>
      <td>snake_case</td>
      <td>
<pre>
int my_var = 0;
</pre>
      </td>
    </tr>
    <tr tr style="background: #FFFFFF">
      <td>Member Variables</td>
      <td>m_snake_case</td>
      <td>
<pre>
int m_timeout;
</pre>
      </td>
    </tr>
    <tr tr style="background: #FFFFFF">
      <td>Functions</td>
      <td>camelCase</td>
      <td>
<pre>
void doSomething() { }
</pre>
      </td>
    </tr>
    <tr tr style="background: #FFFFFF">
      <td>Enumerations</td>
      <td>UPPER_CASE</td>
      <td>
<pre>
enum class COLORS : unsinged
{
    BLACK = 0x000000
}
</pre>
      </td>
    </tr>
  </tbody>
</table>

*Header File:*
<pre>
namespace nested::ns
{
    class MyClass final : public IFace
    {
    private:
        bool m_boolean{false};
        int* m_pointer = nullptr;

        void privateFunction();

    public:
        MyClass() = default;
        explicit MyClass(const int& i);
        virtual ~MyClass() override;

        void classSpecificFunction();

        virtual void inheritedFunction() override;
    }
}
</pre>
