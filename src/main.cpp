#include <iostream>
#include "../lib/cxxopts.hpp"

int main(int argc, char* argv[]) {
    cxxopts::Options options("mygit", "A simple Git-like CLI tool");
    
    // both can not work together
    /*options.add_options()
        ("h,help", "Show help")
        ("v,version", "Show version");

    auto result = options.parse(argc, argv);
    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }
    if (result.count("version")) {
        std::cout << "mygit version 1.0" << std::endl;
        return 0;
    }*/

    if (argc > 1) {
       std::string command = argv[1];

       if (command == "commit") {
           cxxopts::Options commitOptions("commit", "Commit changes");
           commitOptions.add_options()
               ("m,message", "Commit message", cxxopts::value<std::string>())
               ("a,all", "Commit all changes");

           auto commitResult = commitOptions.parse(argc - 1, argv + 1);

           if (commitResult.count("message")) {
               std::cout << "Committing with message: " << commitResult["message"].as<std::string>() << std::endl;
           }

           if (commitResult.count("all")) {
               std::cout << "Committing all changes!" << std::endl;
           }
       } else if (command == "push") {
           cxxopts::Options pushOptions("push", "Push changes");
           pushOptions.add_options()
               ("r,remote", "Remote repository", cxxopts::value<std::string>())
               ("b,branch", "Branch name", cxxopts::value<std::string>());

           auto pushResult = pushOptions.parse(argc - 1, argv + 1);

           std::cout << "Pushing to remote: " << pushResult["remote"].as<std::string>()
                     << " on branch: " << pushResult["branch"].as<std::string>() << std::endl;
       } else {
           std::cout << "Unknown command: " << command << std::endl;
       }
    } else {
       std::cout << "No command provided. Use --help for usage." << std::endl;
    }

    return 0;
}