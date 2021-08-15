// PasswordKeeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "PassKeeper.h"
#include "Render.h"
#include <chrono>
#include <conio.h>
#include <random>

//#include "..\PasswordKeeper\crypto++\aes.h"
//#include "..\PasswordKeeper\crypto++\cryptlib.h"
//#include "..\PasswordKeeper\crypto++\hex.h"
//#include "..\PasswordKeeper\crypto++\base64.h"
//#include "..\PasswordKeeper\crypto++\rijndael.h"
//#include "..\PasswordKeeper\crypto++\modes.h"
//#include "..\PasswordKeeper\crypto++\files.h"
//#include "..\PasswordKeeper\crypto++\osrng.h"
//using namespace CryptoPP;
//using namespace std;
//struct Key {
//    string iv;
//    string key;
//};
//string convert_to_hex(string input) {
//    string output;
//    StringSource(input, true, new HexEncoder(new StringSink(output)));
//    return output;
//}
//
//string convert_from_hex(string hex) {
//    string output;
//    StringSource(hex, true, new HexDecoder(new StringSink(output)));
//    return output;
//}
//
//Key generate_key() {
//    AutoSeededRandomPool rnd;
//   // Key key;
//    SecByteBlock key(0x00, AES::DEFAULT_KEYLENGTH);
//    rnd.GenerateBlock(key, key.size());
//
//
//
//    //random IV
//    SecByteBlock iv(AES::BLOCKSIZE);
//    rnd.GenerateBlock(iv, iv.size());
//    string keystr((const char*)key.BytePtr(), key.size());
//    string ivstr((const char*)iv.BytePtr(), iv.size());
//
//    
//    
//  //  StringSource(key, sizeof(key), new HexEncoder(new StringSink(keyhex)));
//  //  StringSource(iv, sizeof(iv), new HexEncoder(new StringSink(ivhex)));
//
//    Key keyout;
//    keyout.iv = ivstr;
//    keyout.key = keystr;
//    return keyout;
//
//   
//}
//
//string encrypt_AES(Key& key, string& plaintext) {
//    CFB_Mode<AES>::Encryption enc;
//    const byte* keydata = (const byte*)&key.key[0];
//    const byte* ivdata = (const byte*)&key.iv[0];
//    enc.SetKeyWithIV(keydata, key.key.size(), ivdata);
//    string cipher;
//    StringSource(plaintext, true, new StreamTransformationFilter(enc, new HexEncoder(new StringSink(cipher))));
//    return cipher;
//}
//
//string decrypt_AES(Key&key, string&cipher) {
//    CFB_Mode<AES>::Decryption dec;
//    const byte* keydata = (const byte*)&key.key[0];
//    const byte* ivdata = (const byte*)&key.iv[0];
//    dec.SetKeyWithIV(keydata, key.key.size(), ivdata);
//    string plaintext;
//    StringSource(cipher, true, new StreamTransformationFilter(dec, new HexEncoder(new StringSink(plaintext))));
//    return plaintext;
//}
int main()
{
	Render renderer;
	Console console;
	thread render([renderer] {renderer.Menu(); });

	//PassKeeper vault(User("Chris", "1234", 1));
	/*if (vault.unlockVault()) {
		vault.DisplayVault();*/
		//vault.toggle();
	








  //  Key key = generate_key();
  //  string plaintext = "Hello world";
   /// string cipher = encrypt_AES(key, plaintext);
  //  cout << cipher << endl;

   // string word = "abcdefgadsfsadfluyasdfkjahsdfkljahsdf;kljsaf;lkdsaf;lk";
   // string goal = "I have been staring at this computer for far too long.";
   

   
   // std::cout << "Hello World!\n";
}

