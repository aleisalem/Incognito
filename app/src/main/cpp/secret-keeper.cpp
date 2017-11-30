#include <jni.h>
#include <string>

void _1_stringEncoder(int n , char str[] );

extern "C"
JNIEXPORT jstring Java_com_tum_incognito_MainActivity_getURL(JNIEnv* env, jobject obj, jstring mode) {
    const char *tempInput = env->GetStringUTFChars(mode, NULL);
    char output[255];
    if(strcmp(tempInput, "MODE1")==0){
        // Get the "MODE1" url
        _1_stringEncoder(0, output);
        return env->NewStringUTF(output);
    }
    else if(strcmp(tempInput, "MODE2")==0){
        // Get the "MODE2" url
        _1_stringEncoder(1, output);
        return env->NewStringUTF(output);
    }

    return env->NewStringUTF("");
}

void _1_stringEncoder(int n , char str[] )
{
    int encodeStrings_i3 ;

    {
        encodeStrings_i3 = 0;
        switch (n) {
            case 2:
                str[encodeStrings_i3] = '\000';
                encodeStrings_i3 ++;
                break;
            case 1:
                str[encodeStrings_i3] = 'h';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 't';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 't';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'p';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 's';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = ':';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '/';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '/';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'd';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'i';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'c';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 't';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '.';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'l';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'e';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'o';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '.';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'o';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'r';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'g';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '/';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'g';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'e';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'r';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'm';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'a';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'n';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '-';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'e';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'n';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'g';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'l';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'i';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 's';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'h';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '/';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '\000';
                encodeStrings_i3 ++;
                break;
            case 0:
                str[encodeStrings_i3] = 'h';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 't';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 't';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'p';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = ':';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '/';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '/';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'w';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'w';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'w';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '.';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'w';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'e';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 't';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 't';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'e';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'r';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '.';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'c';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'o';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'm';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '/';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 's';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'u';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'c';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'h';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'e';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '/';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '?';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = 'q';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '=';
                encodeStrings_i3 ++;
                str[encodeStrings_i3] = '\000';
                encodeStrings_i3 ++;
                break;
        }
    }
}
