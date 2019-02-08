#include "SD.h"
#include <SPI.h>

namespace nustars {
    class Storage {
    public:
        Storage(char* file);
        void write(char* msg);
        int* read(int& lng);
        void close();

    private:
        bool isInitialized;
        char* fileName;
        File dataFile;
    };
}
