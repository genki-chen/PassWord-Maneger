/*************************************************************************
    > File Name: pwmgr.cpp
    > Author: genki_chen/黄臣
	> No:S170101106
    > Mail: genki_chen@aliyun.com 
    > Created Time: 2017年12月26日 星期二 17时25分22秒
 ************************************************************************/


#include<iostream>
#include<stdlib.h>
#include<string>
#include<list>
#include<fstream>
#include<unistd.h>
#include<curses.h>
using namespace std;


int main()
{
	int flag;
	int i=0;
	int lay=0;
	int ch;
	int arr;
	int t;
	int sum;
	string s1,s2,s3,temp;
	s1="%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	s2="%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	s3="%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	temp="%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	ifstream fiin ("cont");
	ofstream fout ("key",ios::app);
	ifstream fin ("key");
	fiin >> sum;
	cout << "first: " << sum/3 << endl;
	ofstream foout("cont");
	string s4[300];
	
	WINDOW *win1;
	WINDOW *win2;
	WINDOW *win3;
	initscr();
	noecho();
	cbreak();
	clear();
	mvaddstr(15,5,"web_add");
	mvaddstr(19,5,"account");
	mvaddstr(23,5,"password");
	refresh();
	win1 = newwin(3,40,14,15);
	win2 = newwin(3,40,18,15);
	win3 = newwin(3,40,22,15);
	box(win1 , ACS_VLINE, ACS_HLINE);
	box(win2 , ACS_VLINE, ACS_HLINE);
	box(win3 , ACS_VLINE, ACS_HLINE);
	mvwaddstr(win1,1,1,"test");
	mvwaddstr(win2,1,1,"test");
	mvwaddstr(win3,1,1,"test");
	wrefresh(win1);
	wrefresh(win2);
	wrefresh(win3);

	for(t=0;t<sum;t++)
	{
		fin >> s4[t];
	}
	list<string>set1(s4,s4+sum);
	list<string>::iterator p1;

	while(1)
	{
		flag = getch();
		if('j' == flag)
		{
			i++;
			if(i>2)
				i-=3;
		}
		if('k' == flag)
		{
			i--;
			if(i<0)
				i+=3;
		}
		if(27 == flag)
		{
			lay = 0;
		}
		if('q' == flag)
		{
			endwin();
			foout.seekp(0,ios::beg);
			foout << sum << endl;
			cout << "last password have " << sum/3 << endl;
			exit(1);
		}
		if('i' == flag)
		{
			lay = 1;
			temp="%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
			switch(i)
			{
				case 0:
					mvwaddstr(win1,1,1,"                                ");
					wrefresh(win1);
					break;
				case 1:
					mvwaddstr(win2,1,1,"                                ");
					wrefresh(win2);
					break;
				case 2:
					mvwaddstr(win3,1,1,"                                ");
					wrefresh(win3);
					break;
				default:
					break;
			}
		}
		if('w' == flag)
		{
			s4[sum+1] = s1;
			s4[sum+2] = s2;
			s4[sum+3] = s3;
			for(t=1;t<4;t++)
			{
				fout << s4[sum+t] << endl; 
			}
			sum += 3;
			foout.seekp(0,ios::beg);
			foout << sum << endl;
		}
		if('s' == flag)
		{
			p1 = set1.begin();
			while(p1 != set1.end())
			{
				if(s1 == *p1)
				{
					p1++;
					s2 = *p1;
					arr = 1;
					mvwaddstr(win2,1,1,"                                ");
					wrefresh(win2);
					mvwaddstr(win3,1,1,"                                ");
					wrefresh(win3);
					for(int z=0;z < s2.size();z++)
					{
						ch = s2[arr-1];
						if(ch == '%')
							break;
						mvwaddch(win2,1,arr,ch);
						wrefresh(win2);
						arr++;
					}
					p1++;
					s3 = *p1;
					arr = 1;
					for(int z=0;z < s3.size();z++)
					{
						ch = s3[arr-1];
						if(ch == '%')
							break;
						mvwaddch(win3,1,arr,ch);
						wrefresh(win3);
						arr++;
					}
				}
				p1++;
			}
		}

		switch(i)
		{
			case 0:
				wmove(win1,1,1);
				wrefresh(win1);
				break;
			case 1:
				wmove(win2,1,1);
				wrefresh(win2);
				break;
			case 2:
				wmove(win3,1,1);
				wrefresh(win3);
				break;
			default:
				break;
		}
		arr = 1;
		while(lay)
		{
			ch = getch();
			if(27 == ch)
			{
				lay = 0;
				switch(i)
				{
					case 0:
						s1 = temp;
						break;
					case 1:
						s2 = temp;
						break;
					case 2:
						s3 = temp;
						break;
				}
				break;
			}
			switch(i)
			{
				case 0:
					mvwaddch(win1,1,arr,ch);
					wrefresh(win1);
					temp[arr-1] = ch;
					arr++;
					break;
				case 1:
					mvwaddch(win2,1,arr,ch);
					wrefresh(win2);
					temp[arr-1] = ch;
					arr++;
					break;
				case 2:
					mvwaddch(win3,1,arr,ch);
					wrefresh(win3);
					temp[arr-1] = ch;
					arr++;
					break;
				default:
					break;
			}
		}
		
	}
	endwin();
	return 0;
}

