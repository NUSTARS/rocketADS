#include "storage.h"


namespace nustars {
Storage::Storage(String x) {
  isInitialized = false;
  //fileName = (char*)malloc(strlen(x) + 1);
  //strcpy(fileName, x);
  if (!SD.begin(BUILTIN_SDCARD)) {
    Serial.println("Card failed, or not present");
    while (1)
      delay(10);
    return;
  }
  String outputString;
  char outputFile[100];
  outputString = "data0.csv";
  outputString.toCharArray(outputFile, 100);
  int i = 0;
  while (SD.exists(outputFile)) {
    i++;
    outputString = "data";
    outputString += String(i);
    outputString += ".csv";
    outputString.toCharArray(outputFile, 100);
  }
  fileName = outputString;
  isInitialized = true;
  Serial.println(isInitialized);
  dataFile = SD.open(fileName.c_str(), FILE_WRITE);

}

bool Storage::write(String msg) {
  //
  buffer.push_back(msg);
  /*if (dataFile) {
    dataFile.println(msg);
    return true;
  }*/
  //else return false;
  return true;

}

void Storage::save() {
  for (const auto & x : buffer) {
    dataFile.println(x.c_str());
  }
  dataFile.close();
  dataFile = SD.open(fileName.c_str(), FILE_WRITE);
}
}
