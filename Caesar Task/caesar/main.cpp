#include <iostream>
using namespace std;
int main()
{
    // Caesar Method For Encryption and Decryption
    // define a type
    int type;
    cout << "Please enter your type: " << endl;
    cout << "1 -> Encryption" << endl;
    cout << "2 -> Decryption" << endl;
    cin >> type;
    cin.ignore();

    // if the type == 1 -> Encryption
    if(type == 1)
    {
        // massage
        string str;
        cout << "Note: Massage can only be alphabetic" << endl;
        cout << "Enter your massage: " << endl;
        getline(cin , str);

        // key
        int key;
        cout << "Enter your key from 0 to 25: " << endl;
        cin >> key;
        cin.ignore();

        // encrypted output
        string output = str;
        for(int i = 0 ; i < str.size() ; i++)
        {
            // if the char is space it will ignore it
            if(str[i] == 32)
            {
                continue;
            }
            else
            {
                if(str[i] + key > 122)
                {
                    //after z lowercase , move back to a
                    int temp = (str[i] + key) - 122;
                    output[i] = 96 + temp;
                }
                else if(str[i] + key > 90 && str[i] <= 96)
                {
                    //after Z upper , move back to A
                    int temp = (str[i] + key) - 90;
                    output[i] = 64 + temp;
                }
                else
                {
                    output[i] += key;
                }
            }
        }
        cout << "Encrypted Message: " << output << endl;
    }
    else if(type == 2)
    {
        // massage
        string d_str;
        cout << "Note: Massage can only be alphabetic" << endl;
        cout << "Enter your massage: " << endl;
        getline(cin , d_str);

        // key
        int d_key;
        cout << "Enter your key from 0 to 25: " << endl;
        cin >> d_key;
        cin.ignore();

        // decryption
        string d_output = d_str;
        for(int i = 0 ; i < d_str.size() ; i++)
        {
            if(d_str[i] == 32)
            {
                continue;
            }
            else
            {
                if( (d_str[i] - d_key < 97) && (d_str[i] - d_key  > 90) )
                {
                    int temp = (d_str[i] - d_key) + 26;
                    d_output[i] =  temp;
                }
                else if(d_str[i] - d_key < 65)
                {
                    int temp = (d_str[i] - d_key) + 26;
                    d_output[i] =  temp;
                }
                else
                {
                    d_output[i] = d_str[i] - d_key;
                }
            }
        }
        cout << "Decrypted Message: " << d_output << endl;
    }
    else
    {
        cout << "Sorry, Invalid type" << endl;
    }
    return 0;
}
