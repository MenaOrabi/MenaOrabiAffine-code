//FCAI-Programming 1 -2022-Assignment 2
//Programe Name: Affine cipher
//Program Description: Decrypting a message using substitute numbers and back to letters
//last modification date: 23-3-2022
//Menatallah-20210510


#include <iostream>
using namespace std;

//check if value entered is within ascii
int modInverse(int k){
    for(int i=0; i<26; i++){
        int flag= (i*k)%26;
        if(flag==1){
            return i;
        }
    }
    return -1;
}
//encryption code
string encrypt(string plain_text){
    string cipher_text= "";
    for(int i=0; i<plain_text.length(); i++){
        //check if character is upper or lower case
        if(isupper(plain_text[i])){
            cipher_text+= char((5* int(plain_text[i]-65)+ 8)%26 +65);
        }else{
            cipher_text+= char((5* int(plain_text[i]-97)+ 8)%26 +97);
        }
    }
    return cipher_text;
}
//decryption code
string decrypt(string cipher_text){
    string plain_text= "";
    int key_inverse= modInverse(5);
    if(key_inverse==-1){
        return "Not exist";
    }
    for(int i=0; i<cipher_text.length(); i++){
        if(isupper(cipher_text[i])){
            plain_text+= char(((((cipher_text[i]-65- 8)%26+26)%26)*key_inverse)%26+65);
        }else{
            plain_text+= char(((((cipher_text[i]-97- 8)%26+26)%26)*key_inverse)%26+97);
        }
    }
    return plain_text;
}
int main(){
    string plain_text;
    cout<<"Enter plain text: ";
    cin>>plain_text;


    cout<<"\nEncryption:\n";
    string cipher_text= encrypt(plain_text);
    cout<<"Cipher: "<<cipher_text<<endl;

    cout<<"\nDecryption:\n";
    cout<<"Plain Text: "<<decrypt(cipher_text)<<endl;
    return 0;
}

