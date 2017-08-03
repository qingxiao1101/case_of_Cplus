#include <iostream>
#include <string>

using namespace std;



void get_input(string& s)
{
	getline(cin, s);
}

int * check_Anziehungszeichen(string& s)
{
	int * p = new int[2];
	if(s.find("\"")!=string::npos){
		p[0] = s.find_first_of('"');
		p[1] = s.find_last_of('"');
		return p;
	}
	else 
		return NULL;
}
int * check_Strichenszeichen(string& s)
{
	int * p = new int;
	if(s.find("//")!=string::npos){
		*p = s.find("//");
	}
	return p;
}
int * check_Sternszeichen(string& s)
{
	int * p = new int[2];
	if((s.find("/*")!=string::npos)&&(s.find("*/")!=string::npos)){
		p[0] = s.find("/*");
		p[1] = s.find("*/");
		return p;
	}
	else 
		return NULL;
}

string delete_streichen(string& s)
{
	
	string subs;
	if(s.find("//")!= string::npos) {
		subs = s.substr(0,s.find("//"));
		return subs;
	}
	else return s; 
}

string delete_stern(string& s)
{
	string subs,subs1,subs2;
	if((s.find("/*")!= string::npos)&&(s.find("*/")!= string::npos)){
		subs1 = s.substr(0,s.find("/*"));
		subs2 = s.substr(s.find("*/")+2);
		subs = subs1 + subs2;
		return subs;
	}
	else {
		return s;
	}
}

string delete_Commentar(string& s)
{
	string subs = s,subs1;
	int * stern;
	int * streichen;
	stern  = check_Sternszeichen(s);
	streichen = check_Strichenszeichen(s);

	if((stern!=NULL) && (streichen!=NULL))	
	{
		if((*streichen) < (*stern))
		{
			subs1 = delete_streichen(s); 
			subs = delete_stern(subs1);
		}
		else{
			subs1 = delete_stern(s);
			subs = delete_streichen(subs1); 
		}
		
	}
	else{
		subs1 = delete_streichen(s); 
		subs = delete_stern(subs1);
	}
	return subs;
}

void print(string& s)
{
	cout << "the finally string is:" << endl;
	cout << s << endl;
}

void analysis_input(string& res)
{
	int * p_anziehung;
	int * p_stern;
	int * p_streichen;
	string tmp=res;
	p_stern  = check_Sternszeichen(res);
	p_streichen = check_Strichenszeichen(res);
	p_anziehung = check_Anziehungszeichen(res);
	if((p_stern==NULL) && (p_streichen==NULL)) print(tmp);
	else{
			if(p_anziehung==NULL){
				tmp = delete_Commentar(res);//
			}
			else if(p_stern!=NULL){
				if((*p_stern> *p_anziehung)&&(*p_stern < *++p_anziehung))
					;
				else
					tmp = delete_Commentar(res);//
			}
			else if(p_streichen!=NULL){
				if((*p_streichen> *p_anziehung)&&(*p_streichen < *++p_anziehung))
					;
				else
					tmp = delete_Commentar(res);//
			}
			print(tmp);
	}
	
}