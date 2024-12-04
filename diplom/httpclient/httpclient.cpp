#include "httpcl.h"


// Main function with retry logic for different ports (first HTTP, then HTTPS, reverse on failure)
int main(int argc, char** argv)
{
    try
    {
        if (argc != 4 && argc != 5)
        {
            std::cerr <<
                "Usage: http-client-sync-ssl <host> <port> <target> [<HTTP version: 1.0 or 1.1(default)>]\n" <<
                "Example:\n" <<
                "    http-client-sync-ssl www.example.com 443 /\n" <<
                "    http-client-sync-ssl www.example.com 443 / 1.0\n";
            return EXIT_FAILURE;
        }

        auto const host = argv[1];
        auto const target = argv[3];
        int version = argc == 5 && !std::strcmp("1.0", argv[4]) ? 10 : 11;

        // First attempt with HTTP (port 80)
        try
        {
            std::cout << "Attempting to connect to " << host << " via HTTP (port 80)...\n";
            perform_request(host, "80", target, version);
            return EXIT_SUCCESS; // If successful, exit early
        }
        catch (const std::exception& e)
        {
            std::cerr << "Failed with HTTP (port 80), trying HTTPS (port 443)...\n";
        }

        // If HTTP failed, try HTTPS (port 443)
        try
        {
            std::cout << "Attempting to connect to " << host << " via HTTPS (port 443)...\n";
            perform_request(host, "443", target, version);
            return EXIT_SUCCESS; // If successful, exit early
        }
        catch (const std::exception& e)
        {
            std::cerr << "Failed with HTTPS (port 443), trying HTTP (port 80)...\n";
        }

        // If HTTPS failed, try HTTP again (port 80)
        try
        {
            std::cout << "Attempting to connect to " << host << " via HTTP (port 80) again...\n";
            perform_request(host, "80", target, version);
            return EXIT_SUCCESS; // If successful, exit early
        }
        catch (const std::exception& e)
        {
            std::cerr << "Failed with HTTP (port 80) again, exiting.\n";
            throw std::runtime_error("Failed to connect to the server on both HTTP and HTTPS ports.");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
