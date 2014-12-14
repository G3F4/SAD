/* Test tools set */

#ifndef NDEBUG
#define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << " | Errors message: " << message << std::endl; \
            std::exit(EXIT_FAILURE); \
        } \
        std::cout << "* ";\
    } while (false)
#else
#define ASSERT(condition, message) do { } while (false)
#endif