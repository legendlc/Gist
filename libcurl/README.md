# About libcurl

Compiling the Program

Your compiler needs to know where the libcurl headers are located. Therefore you must set your compiler's include path to point to the directory where you installed them. The 'curl-config'[3] tool can be used to get this information:

$ curl-config --cflags

Linking the Program with libcurl

When having compiled the program, you need to link your object files to create a single executable. For that to succeed, you need to link with libcurl and possibly also with other libraries that libcurl itself depends on. Like the OpenSSL libraries, but even some standard OS libraries may be needed on the command line. To figure out which flags to use, once again the 'curl-config' tool comes to the rescue:

$ curl-config --libs

SSL or Not

libcurl can be built and customized in many ways. One of the things that varies from different libraries and builds is the support for SSL-based transfers, like HTTPS and FTPS. If a supported SSL library was detected properly at build-time, libcurl will be built with SSL support. To figure out if an installed libcurl has been built with SSL support enabled, use 'curl-config' like this:

$ curl-config --feature

And if SSL is supported, the keyword 'SSL' will be written to stdout, possibly together with a few other features that could be either on or off on for different libcurls.
