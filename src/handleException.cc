#include "main.ih"

int handleException()
try
{
    rethrow_exception(current_exception());
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Unexpected exception\n";
    return 1;
}
