//
// Created by lioze on 1/21/2023.
//

#ifndef SERVERMILESTONEEX3_GLOBALS_H
#define SERVERMILESTONEEX3_GLOBALS_H

using namespace std;
#include <string>

namespace Globals{
    static const string UPLOAD_UN_CLASSIFIED_DESCRIPTION = "";
    static const string ALGORITHM_SETTINGS_DESCRIPTION = "2. algorithm settings";
    static const string CLASSIFY_DATA_DESCRIPTION = "3. classify data";
    static const string DISPLAY_RESULT_DESCRIPTION = "4. display results";
    static const string DOWNLOAD_RESULT_DESCRIPTION = "5. download results";
    static const string STATUS_CODE_SUCCESS = "200";
    static const string STATUC_CODE_FAILURE = "400";
    static const string UPLOAD_AN_CLASSIFIED_DATA_TRAIN = "Please upload your local train CSV file.";
    static const string UPLOAD_AN_CLASSIFIED_DATA_TRAIN_BACK_N = "Please upload your local train CSV file.\n";

    static const string UPLOAD_AN_CLASSIFIED_DATA_TEST = "Please upload your local test CSV file.";
    static const string UPLOAD_AN_CLASSIFIED_DATA_TEST_BACK_N = "Please upload your local test CSV file.\n";

    static const string UPLOAD_COMPLETE = "Upload complete.";
    static const string UPLOAD_COMPLETE_BACK_N = "Upload complete.\n";

    static const string END_OF_FILE = "END_OF_FILE";
    static const string END_OF_FILE_BACK_N= "END_OF_FILE\n";
    static const string INVALID_PATH = "INVALID_PATH";
    static const string INVALID_PATH_BACK_N = "INVALID_PATH\n";
    static const string EXIT_OPTION = "8\n";
    static const string EXIT_DESCRIPTION = "8. exit";
    static const string EXIT_DESCRIPTION_BACK_N = "8. exit\n";

    static const string DISPLAY_RESULT_SYNCRONIZED = "DISPLAY_RESULT_SYNCRONIZED";
    static const string DISPLAY_RESULT_SYNCRONIZED_BACK_N = "DISPLAY_RESULT_SYNCRONIZED\n";
    static const string DISPLAY_RESULT_UN_SYNCRONIZED = "DISPLAY_RESULT_UN_SYNCRONIZED";
    static const string DISPLAY_RESULT_UN_SYNCRONIZED_BACK_N = "DISPLAY_RESULT_UN_SYNCRONIZED\n";
    static const string  DISPLAY_RESULT_END_BACK_N = "Done.\n";
    static const string  DISPLAY_RESULT_END = "Done.";
    static const string PLEASE_UPLOAD_DATA = "please upload data";
    static const string PLEASE_CLASSIFY_DATA = "please classify the data";



    static const int SERVER_PORT = 5060;
}


#endif //SERVERMILESTONEEX3_GLOBALS_H
