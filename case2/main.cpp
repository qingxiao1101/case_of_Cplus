#include <iostream>
#include <string>


using namespace std;

int main(int argc, char * argv[])
{
	string puffer,tmp;
	string::iterator iter,t = tmp.begin();
	getline(cin, puffer);

	if(argv[1]!='\0'){
		string buf(argv[1]);
		int i,count = buf.size();
		cout << buf << endl;
		cout << "count is:" << count<< endl;
		for(iter = puffer.begin(),i=0;iter != puffer.end();iter++,i++,t++){
			*iter = (*iter)^buf[i];//(buf[count/2]);
			*t = (*iter)^buf[i];
			cout << tmp[i] <<endl;
			if(i==count-1) i=0;
		}
		
		cout << puffer[0]<< endl;
	}

	else cout << puffer << endl;

	return 0;
}






