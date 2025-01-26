#include "main.ih"

int handleException()
try
{
    rethrow_exception(std::current_exception());
}
catch (std::exception const &exc)
{
    std::cerr << exc.what() << '\n';
    return 1;
}
catch (...)
{
    std::cerr << "Unexpected exception\n";
    return 1;
}
