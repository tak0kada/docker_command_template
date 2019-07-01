#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include <string>

int main(const int argc, const char* const argv[])
{
    //--------------------------------------------------------------------------
    // parse options
    //--------------------------------------------------------------------------
    namespace po = boost::program_options;

    po::options_description opt("");
    opt.add_options()
        ("input", po::value<std::string>(), "path to input file")
        ("output", po::value<std::string>(), "path to output file")
        ("param", po::value<double>(), "some parameter");

    po::variables_map vm;
    try
    {
        po::store(po::parse_command_line(argc, argv, opt), vm);
    }
    catch (const po::error_with_option_name& e)
    {
        std::cout << e.what() << std::endl;
    }
    vm.notify();

    if (!vm.count("input") || !vm.count("output"))
    {
        std::cerr << opt << std::endl;
        return 1;
    }

    auto input_path  = "/hostroot" + vm["input"].as<std::string>();
    auto output_path = "/hostroot" + vm["output"].as<std::string>();
    // auto param = vm["param"].as<double>();


    //--------------------------------------------------------------------------
    // I/O
    //--------------------------------------------------------------------------
    std::ifstream ifs(input_path);
    std::ofstream ofs(output_path);

    bool file_opened = true;
    if (!ifs.good())
    {
        std::cerr << "Error: Cannot open " + input_path << "." << std::endl;
    }
    else if (!ofs.good())
    {
        std::cerr << "Error: Cannot open " + output_path << "." << std::endl;
    }
    if (!file_opened)
    {
        return 1;
    }


    return 0;
}
