#include<bits/stdc++.h>
using namespace std;

void generate_sequence(vector < vector <int> >&key_seq);
void generate_key(vector <int> &key);

vector<int> encrypt(string str, vector<vector<int> >key_seq,vector<int>key, vector<int>&seq){
 	vector <int> cipher(str.length());
 	srand(time(NULL));
 	for(int i=0;i<=str.length()-4;i+=4)
    {
 		int seq_num = rand()%256;
 		seq.push_back(seq_num);

 		for(int j=0;j<4;j++){
 			int key_num = key_seq[seq_num][j];
 			int temp = ((int)str[i+j]) ^ key[key_num];
 			cipher[i+j] = temp;
		}
	}
	return cipher;
}

vector<int> decrypt(vector<int>cipher,vector<vector<int> >key_seq,vector<int>key,vector<int>seq){
	vector <int> decipher(cipher.size());

 	for(int i=0;i<seq.size();i++)
    {
 		int seq_num = seq[i];
 		for(int j=0;j<4;j++){
 			int key_num = key_seq[seq_num][j];
 			int t = cipher[4*i+j] ^ key[key_num];
            decipher[4*i+j] =t;
		}
	}
	return decipher;
}
int main(){

	cout<<"Enter the string"<<endl;
	string str;
	getline(cin, str);

	int l = str.length();
	if(l%4!=0){
		int t = l%4;
		t = 4-t;
		str.append(t,'$');
	}
    vector <vector <int> > key_seq(256);
	generate_sequence(key_seq);

	vector <int> key(4);
	generate_key(key);

	vector <int> seq;
	vector <int> cipher = encrypt(str,key_seq,key,seq);
	cout<<endl<<"Cipher_Text: "<<endl;
	for(int i=0;i<cipher.size();i++)
    {
        cout<<(char)cipher[i]<<" ";
    }
	cout<<endl;
	cout<<endl<<"Initial String was:"<<endl;
	vector<int> decipher = decrypt(cipher,key_seq,key,seq);

	for(int i=0;i<decipher.size();i++)
    {
        cout<<(char)decipher[i];
    }
	cout<<endl;

	return 0;
}
void generate_sequence(vector < vector <int> >&key_seq){
	vector <int> s(4,0);
	int i = 0;
	while(i<256){
		key_seq[i] = s;
		s[0]++;

		if(s[0]>=4){
			s[0] %= 4;
		}
			s[1]++;
		if(s[1]>=4){
			s[1] %= 4;
		}
			s[2]++;
		if(s[2]>=4){
			s[2] %= 4;
		}
			s[3]++;
		if(s[3]>=4){
			break;
		}
		i++;
	}
}
void generate_key(vector <int> &key){
	srand(time(NULL));
	for(int i=0;i<4;i++){
		key[i] = rand()%256;
	}
}
