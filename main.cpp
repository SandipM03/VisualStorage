#include "code/arcTOvid.h"
#include "code/vidTOarc.h"
#include "code/compare.h"
#include "code/arcmaker.h"

int arcvid() {
    std::string archivelocation = "../arcout/archtester.bin";
    std::string videopath = "../videos/videolar.mp4";
    vidmaker(archivelocation, videopath);
    // std::cout << "done" << std::endl;
    return 0;
}

int vidarc() {
    std::string videopath = "../videos/videolar.mp4";
    std::string outpath = "../arcreco/recovered.bin";
    arcrest(videopath, outpath);
    // std::cout << "done" << std::endl;
    return 0;
}

int comp() {
    std::string iniarch = "../arcout/archtester.bin";
    std::string outpath = "../arcreco/recovered.bin";
    compare(iniarch, outpath);
    return 0;
}

int arcmk()
{
    fs::path directorypath = "../subjectX";
    // fs::path directorypath = "./tst1";

    // fs::path archivepathoutput ="./arcout/archlar.bin";
    fs::path archivepathoutput ="../arcout/archtester.bin";

        // for checking if the directory exists or not 
    if (exists(directorypath) && is_directory(directorypath)) { 
        discover(directorypath,archivepathoutput);
    } 
    else { 
        std::cerr << "Directory not found." << std::endl; 
    } 
    return 0;
}

void test() {//4
    arcmk();
    arcvid();
    vidarc();
    comp();
}

void youcompare() {
    std::string origpath = "../arcout/archtester.bin";
    std::string videopath = "../videos/videoplayback.webm";
    std::string outpath = "../arcreco/yourecovered.bin";
    arcrest(videopath, outpath);
    compare(origpath, outpath);
}

int main() {

    int choice=5;
    
    switch(choice) {
        case 0:
            arcvid();
            break;
        case 1:
            vidarc();
            break;
        case 2:
            comp();
            break;
        case 3:
            arcmk();
            break;
        case 4:
            test();
            break;
        case 5:
            youcompare();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
    }
    std::cout << "done" << std::endl;
    return 0;
}

