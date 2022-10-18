/*
 * @Description: 
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-15 16:44:48
 */


#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(in(std::cin), in(), std::cout << (_1 * 3) << " ");
}
