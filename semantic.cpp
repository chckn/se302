extern "C"
{
#include "mylang.tab.h"
}
#include "assembly.h"

vector<SYMBOL*> t_vec;
map<string,int> t_tbl;
Expnode::~Expnode()
{
}
string ptype(int type)
{
	if(type==-1)
		return "void";
	if(type>=t_vec.size() || type<0)
		return "NON-TYPE";
	string szstr,typestr;
	char s[10];
	int j=type;
//	fprintf(stderr,"\tptype:%d\n",type);
	SYMBOL *i=t_vec[j];
	switch(i->acc)
	{
		case SYMBOL::VAR:
			typestr="BASIC ";
			break;
		case SYMBOL::CLASS:
			typestr="CLASS ";
			break;
		case SYMBOL::ARRAY:
			typestr="ARRAY ";
	}
	while(i->type!=j)
	{
		sprintf(s,"[%d]",i->size);
		szstr=s+szstr;
		j=i->type;
		i=t_vec[j];
	}
	return typestr+i->name+szstr;

}
int arraytype(int t,int step)
{
	SYMBOL *s=t_vec[t];
	for(int i=1;i<=step;i++)
	{
		t=s->type;
		s=t_vec[t];
		//BUG.The step may not enough
	}
	return t;
}
int getype(Node *tp,ERRMSG& e)
{
	fprintf(stderr,"tp-check:%s\n",tp->name);
	if(strcmp(tp->name,"IDENT")==0)
	{
		if(t_tbl.find(tp->str)==t_tbl.end())
		{
			fprintf(stderr,"ERR10\n");
			e=e+" Type:"+tp->str+" is not exists\n";
			return -2;
		}
		return t_tbl[tp->str];
	}
	else
	{
		if(strcmp(tp->name,"INTEGER")==0)
			return 0;
		else if(strcmp(tp->name,"BOOLEAN")==0)
			return 1;
		return -2;
	}
}

bool symbase::isempty(Node *nd)
{
	if(strcmp(nd->name,"EMPTY")==0)
		return true;
	return false;
}
void symbase::unrolling(const Node* nd,vector<Node*>& v)
{
	Node *i=nd->first;
	while(i!=NULL)
	{
		v.push_back(i);
		i=i->next;
	}
}
void symbase::add_var(Node *args,ERRMSG& e)
{
	SYMBOL *symb;
	Node *i=args,*j=i->first;//i:args,j:arg
	while(!isempty(j))
	{
		fprintf(stderr,"typecheck,i:%s,j:%s\n",i->name,j->name);
		symb=getarg(j,e);
		if(exists(symb->name))
		{
			fprintf(stderr,"ERR11\n");
			e=e+" Name:"+symb->name+" is already exists\n";
			return;
		}
		m_var[symb->name]=symb;
		i=i->last;
		j=i->first;
	}
}
SYMBOL* symbase::getarg(Node *arg,ERRMSG& e)
{
	//VAR IDENT IS type ';'
	fprintf(stderr,"type of arg:%s\n",arg->name);
	SYMBOL* s=new SYMBOL(SYMBOL::VAR);
	s->name=arg->first->next->str;
	Node* tp=arg->last->first;
	s->type=getype(tp,e);
	s->size=0;
	return s;
}
void symbase::space(int n)
{
	for(int i=0;i<n;i++)
		cout<<' ';
}
void symfunc::print(int n)
{
	space(n);
	cout<<"function name:"<<name<<endl;
	space(n+1);
	cout<<"Return type:"<<ptype(this->type)<<endl;
	space(n+1);
	cout<<"Parameter:"<<endl;
	for(int i=0;i<m_parameter.size();i++)
	{
		space(n+2);
		cout<<m_parameter[i]->name<<"->"<<ptype(m_parameter[i]->type)<<endl;
	}
}
SYMBOL::SYMBOL(ACCTYPE _acc):acc(_acc)
{

}
void symfunc::parainit(Node *var,Node* header,ERRMSG& e)
{
	Node *i=var->first;
	Node *j=header->first->first;//argument
	fprintf(stderr,"In parainit,i:%s,j:%s\n",i->name,j->name);
	if(isempty(i) || isempty(j))
	{
		if(!strcmp(i->name,j->name))
			;//
		return;
	}
	//i is nevar
	Node *it;
	SYMBOL *symb;
	vector<string> parse;
	do
	{

		fprintf(stderr,"init,i:%s\n",i->name);
		it=i->first;
		fprintf(stderr,"Loop,it:%s\n",it->name);
		while(strcmp(it->name,"IDENT")!=0 && it!=NULL)
		{
			fprintf(stderr,"it:%s\n",it->name);
			it=it->first;
		}
		if(it)
			parse.push_back(it->str);
		i=i->last;
		fprintf(stderr,"push_finshed,i:%s\n",i->name);
	}while(strcmp(i->name,"var")!=0);
	fprintf(stderr,"IDENT finding finish\n");

	int k;
	j=header->first;
	i=j->first;

	fprintf(stderr,"typecheck,i:%s,j:%s\n",i->name,j->name);
	while(!isempty(i))
	{
		symb=getarg(i,e);
		for(k=0;k<parse.size();k++)
			if(parse[k]==symb->name && !exists(symb->name))
			{
				m_var[symb->name]=symb;
				m_parameter.push_back(symb);
				break;
			}
		if(k==parse.size())
		{
			fprintf(stderr,"ERR16\n");
			e=e+"Arguments in Function "+this->name+"is not match\n";
		}
		j=j->last;
		i=j->first;
	}

	fprintf(stderr,"m_parameter set finish\n");
	j=header->last;//retype
	i=j->first;
	fprintf(stderr,"%s_typecheck,i:%s,j:%s\n",name.c_str(),i->name,j->name);
	if(isempty(i))
		this->type=-1;
	else
	{
		this->type=getype(j->last->first,e);
	}
}
symfunc::symfunc(Node *f,symclass* c,ERRMSG& e):SYMBOL(SYMBOL::FUNC),parent(c)
{		
	vector<Node*> lst;
	unrolling(f,lst);
	fprintf(stderr,"checkident:%s-%s\n",lst[1]->str,lst[9]->str);
	name=lst[1]->str;
	if(strcmp(lst[1]->str,lst[9]->str)!=0)
	{
		e=e+" FUNCTION "+name+"& END FUNCTION "+lst[9]->str+" is not match\n";
	}
	parainit(lst[2],lst[3],e);
	add_var(lst[5],e);
	code=lst[7];
}
void symbase::add_func(Node* f,symclass* c,ERRMSG& e)
{
	symfunc *newfunc=new symfunc(f,c,e);
	if(exists(newfunc->name)){
		fprintf(stderr,"ERR12\n");
		e=e+" Name "+newfunc->name+" is already exists\n";
		return;
	}
	m_var[newfunc->name]=newfunc;
}
void symprog::add_func(Node*f,symclass* c,ERRMSG&e)
{
	string str;
	symbase::add_func(f,c,str);
	if(str=="")
		program->add_func(f,c,e);
	else
		e+=str;
	
}
bool symcode::typecheck(ERRMSG& error)
{
	string e;
	traversal(code,e);
	if(e=="")
		return true;
	error+=e;
	return false;

}
bool symclass::typecheck(ERRMSG& e)
{
	bool pass=true;
	for(auto it=m_var.begin();it!=m_var.end();++it)
	{
		if(it->second->acc==SYMBOL::FUNC)
		{
			e+="Class:"+name+" Func:"+it->second->name+'\n';
			pass=((symfunc*)it->second)->typecheck(e);
			if(!pass)
				return pass;
			else
				e+=" Typecheck Succeed\n";
		}
	}
}
symclass::symclass():SYMBOL(ACCTYPE::CLASS)
{
	name="program";
}
symclass::symclass(Node* f,ERRMSG& e):SYMBOL(ACCTYPE::CLASS)
	{
		vector<Node*> lst;
		unrolling(f,lst);
		name=lst[1]->str;
		int i=3;//index of args
		if(strcmp(lst[2]->name,"IS_CLASS_EXTENDS")==0)
		{
			i++;
			auto it=t_tbl.find(lst[3]->str);
			if(it==t_tbl.end() || t_vec[it->second]->acc!=SYMBOL::CLASS)
			{
				fprintf(stderr,"ERR13\n");
				e=e+" Extends Class:"+lst[3]->str+" is not exists\n";
			}
			else
			{
				m_extends=static_cast<symclass*>(t_vec[it->second]);
			}
		}
		else
			m_extends=NULL;
		add_var(lst[i],e);//arguments
		Node * nd=lst[i+1];
		while(!isempty(nd->first))
		{
			add_func(nd->first,this,e);
			nd=nd->last;	
		}	
	}
	void symclass::print(int n)
	{
		space(n);
		cout<<"Class Name:"<<name<<endl;
		if(m_extends)
		{
			space(n+1);
			cout<<"Extends:"<<m_extends->name<<endl;
		}
		symbase::print(n+1);	

	}
	void symprog::add_class(Node *c,ERRMSG& e)
	{
		symclass *newcls=new symclass(c,e);
		
		if(t_tbl.find(newcls->name)!=t_tbl.end())
		{
			fprintf(stderr,"ERR14\n");
			e=e+" Type:"+newcls->name+" is already exists\n";
			return;
		}
		t_tbl[newcls->name]=t_vec.size();
		newcls->type=t_vec.size();
		//fprintf(stderr,"\tADD class:%s,%d\n",newcls->name.c_str(),newcls->acc);
		t_vec.push_back(newcls);
		//m_var[newcls->name]=newcls;
	}
	void symprog::add_array(Node *arr,ERRMSG& e)
	{
		Node *ident=arr->first->next;
		Node *num=ident->next->next;
		int typeno=getype(arr->last->first,e);
		if(typeno<0)
			return;
		if(t_tbl.find(ident->str)!=t_tbl.end())
		{
			fprintf(stderr,"ERR15\n");
			e=e+" Type:"+ident->str+" is already exists\n";
			return;
		}	
		SYMBOL *s=new SYMBOL(SYMBOL::ARRAY);
		s->type=typeno;
		s->size=num->integer;
		//fprintf(stderr,"new type %s(%d) is %d[%d]\n",ident->str,t_vec.size(),typeno,s->size);
		t_tbl[ident->str]=t_vec.size();
		t_vec.push_back(s);
	}
	void symprog::print()
	{
			
		cout<<"program"<<endl;
		cout<<" TYPE LIST\n";
		for(map<string,int>::iterator it=t_tbl.begin();it!=t_tbl.end();++it)
		{
			space(2);
			cout<<it->first<<"::"<<ptype(it->second)<<endl;
		}
		cout<<" CLASS LIST"<<endl;
		for(int i=0;i<t_vec.size();i++)
			if(t_vec[i]->acc==SYMBOL::CLASS)
			{
				((symclass*)t_vec[i])->print(2);
			}
		symbase::print(1);	
		
	}
symprog::symprog()
	{
		//init t_vec,t_tbl
		SYMBOL *INT=new SYMBOL(SYMBOL::VAR),*BOOL=new SYMBOL(SYMBOL::VAR);
		INT->type=0;
		INT->size=1;
		INT->name="integer";
		BOOL->type=1;
		BOOL->size=1;
		BOOL->name="boolean";
		t_vec.clear();
		t_vec.push_back(INT);
		t_vec.push_back(BOOL);
		t_tbl["integer"]=0;
		t_tbl["boolean"]=1;
		program=new symclass();
	}
	bool symprog::typecheck(ERRMSG& e)
	{
		ERRMSG e1;
		vector<symfunc*> m_func;
		vector<symclass*> m_cls;
		for(map<string,SYMBOL*>::iterator it=m_var.begin();it!=m_var.end();++it)
		{
			switch(it->second->acc)
			{
				case SYMBOL::FUNC:
					m_func.push_back((symfunc*)it->second);
					break;
				case SYMBOL::CLASS:
					m_cls.push_back((symclass*)it->second);
					break;
			}
		}
		bool chk,pass=true;
		for(int i=0;i<m_cls.size();i++)
			pass=pass & m_cls[i]->typecheck(e1);
		if(e1!="")
			e=e1;
		e1="";
		for(int i=0;i<m_func.size();i++)
		{
			e=e+"Func:"+m_func[i]->name+'\n';
			chk=m_func[i]->typecheck(e);
			if(chk)
				e+=" Typecheck Succeed\n";
			pass=pass & chk;
		}
		e+="program()\n";
		pass=pass & symcode::typecheck(e);
		return pass;
	}	
	void symprog::run(Node *head,bool pr)
	{
		string error;
		vector<Node*> v;
		unrolling(head,v);
		sem_declar(v[2],error);
		add_var(v[4],error);
		if(error!="")
		{
			if(pr)
				cout<<error<<endl;
			return;
		}
		code=v[6];
		if(pr)
		{
			print();
			if(typecheck(error))
				cout<<"All Type Check Passed;\n";
			else
				cout<<error<<endl<<"Typecheck failed;\n";
	
		}
	}
void symbase::print(int n)
{
	vector<symfunc*> m_func;
	vector<symclass*> m_cls;
	space(n);
	cout<<"VAR LIST"<<endl;
	for(map<string,SYMBOL*>::iterator it=m_var.begin();it!=m_var.end();++it)
	{
		switch(it->second->acc)
		{
			case SYMBOL::VAR:
				space(n+1);	
				cout<<it->first<<"->"<<ptype(it->second->type)<<endl;
				break;
			case SYMBOL::FUNC:
				m_func.push_back((symfunc*)it->second);
				break;
		}
	}
	if(m_func.size()>0)
	{
		space(n);
		cout<<"FUNCTION LIST"<<endl;
		for(int i=0;i<m_func.size();i++)
			m_func[i]->print(n+1);
	}
}
SYMBOL* symbase::find(string str)
{
	if(m_var.find(str)==m_var.end())
		return NULL;
	return m_var[str];
}
SYMBOL* symclass::find(string str)
{
	SYMBOL *s=symbase::find(str);
	if(s) return s;
	if(m_extends)
		s=m_extends->find(str);
	return s;
}
SYMBOL* symfunc::find(string str)
{
	SYMBOL *s=symbase::find(str);
	if(s) return s;
	if(parent)
		s=parent->find(str);
	return s;
}
bool symbase::exists(string str)
{
	if(t_tbl.find(str)!=t_tbl.end())
		return true;
	if(m_var.find(str)!=m_var.end())
		return true;
	return false;
}
Expnode::Expnode(Node* nd,NDTYPE t)
{
	str=nd->str;
	integer=nd->integer;
	name=nd->name;
	first=nd->first;
	last=nd->last;
	next=nd->next;
	type=t;
}
Varnode::Varnode(Node *nd,SYMBOL* s):Expnode(nd,NDTYPE::VAR),sym(s)
{
//	fprintf(stderr,"Varnode(),%x,%x\n",nd,s);
	valtype=sym->type;
}
void Arrnode::getIndices(vector<Node*>& vec)
{
	Node* i=this->last;
	while(strcmp(i->name,"indices")==0)
	{
		vec.push_back(i->first);	
		i=i->last;
	}	
}
Arrnode::Arrnode(Node* nd,SYMBOL* s):Varnode(nd,s)
{
	type=NDTYPE::ARR;
	vector<Node*> v;
	getIndices(v);
	valtype=arraytype(s->type,v.size());	
}
Funcnode::Funcnode(Node* nd,symfunc* f):Expnode(nd,NDTYPE::FUNC),sym(f)
{
	valtype=sym->type;		
}
void Funcnode::getParameter(vector<Expnode*>& vec)
{
	Node* nevalues=this->last->first;
	if(strcmp(nevalues->name,"EMPTY")==0)
		return;		
	Node *i;
	while(strcmp(nevalues->name,"nevalues")==0)
	{
		vec.push_back((Expnode*)nevalues->first);
		nevalues=nevalues->last;
	}	
}
SYMBOL* symcode::getsym(Node* ident,ERRMSG& e)
{
	fprintf(stderr,"getsym:symbol name:%s\n",ident->str);
	SYMBOL* s;

	if((s=find(ident->str))==NULL)
	{
		fprintf(stderr,"ERR:01\n");
		e=e+" variable "+ident->str+" not found\n";
		return NULL;
	}
	
	return s;
}
bool symcode::isname(Node* nd,const char *str)
{
	if(strcmp(nd->name,str)==0)
		return true;
	return false;
}
void symcode::setvar(Node*& var,ERRMSG& e)
{
	vector<Node*> v;
	unrolling(var,v);
	
	SYMBOL *s;
	if(isname(v[0],"IDENT"))
		s=getsym(v[0],e);
	else
		s=((Varnode*)v[0])->sym;
	if(s==NULL)
		return;
	
	symclass* cls;
	if(v.size()==3)//var . IDENT
	{
//		fprintf(stderr,"NewAcc:%d,name:%s\n",t_vec[s->type]->acc,s->name.c_str());
		Varnode* varnd=(Varnode*)v[0];
		if(t_vec[varnd->valtype]->acc!=SYMBOL::CLASS)
		{
			fprintf(stderr,"ERR:02\n");
			e=e+" "+s->name+" is not a class\n";
			//s->name is not a class
			return;
		}
		cls=(symclass*)(t_vec[varnd->valtype]);
		
//		fprintf(stderr,"getsym:symbol name:%s.%s\n",ident->str,v[2]->str);
		if((s=cls->find(v[2]->str))==NULL)
		{
			
			fprintf(stderr,"ERR:03\n");
			e=e+" Class "+cls->name+" doesn't have member "+v[2]->str;
			return;
		}
	}		
	if(isname(var->last,"indices"))
	{
		Arrnode *anode=new Arrnode(var,s);
		var=anode;
		return;

	}	
	Varnode *newnode=new Varnode(var,s);	
	var=newnode;
}
void symcode::setfcall(Node*& fcall,ERRMSG& e)
{
	vector<Node*> v;
	unrolling(fcall->first,v);
	SYMBOL* s=NULL;
	fprintf(stderr,"fcall:type-%s\n",v[0]->name);
	if(isname(v[0],"var"))
	{
		symclass* cls;
		Varnode* varnd=(Varnode*)v[0];
		s=varnd->sym;
		if(t_vec[varnd->valtype]->acc!=SYMBOL::CLASS)
		{
			fprintf(stderr,"ERR:02F\n");
			e=e+" "+s->name+" is not a class\n";
			//s->name is not a class
			return;
		}
		cls=(symclass*)(t_vec[varnd->valtype]);

		fprintf(stderr,"getsym:symbol name:%s.%s\n",s->name.c_str(),v[2]->str);
		if((s=cls->find(v[2]->str))==NULL)
		{

			fprintf(stderr,"ERR:03F\n");
			e=e+" Class "+cls->name+" doesn't have member "+v[2]->str;
			return;
		}

	}
	else
		s=getsym(v[0],e);
	if(s==NULL)
		return;
	if(s->acc!=SYMBOL::FUNC)
	{
		fprintf(stderr,"ERR:04\n");
		e=e+" "+s->name+" is not a function\n";
		//s->name is not a function
		return;
	}
	//	fprintf(stderr,"setfcall:%d,%s\n",s->acc,s->name.c_str());
	Funcnode* f=new Funcnode(fcall,static_cast<symfunc*>(s));
	vector<Expnode*> vec;
	f->getParameter(vec);
	//	fprintf(stderr,"funcnode %d %s,sz:%d established success\n",f->sym->acc,f->sym->name.c_str(),f->sym->m_parameter.size());
	//	fprintf(stderr,"value?%x",f->sym->m_parameter[0]);
	for(int i=0;i<f->sym->m_parameter.size();i++)
	{
		if(!check(vec[i],f->sym->m_parameter[i]->type,e))
			return;
	}	
	//	fprintf(stderr," Parameter get finished\n");
	fcall=f;

}
bool symcode::check(const Expnode* nd,int vtype,ERRMSG& e)
{
	if(nd->valtype==vtype)
		return true;
	fprintf(stderr,"ERR:05R,valtype:%s,vtype:%s\n",ptype(nd->valtype).c_str(),ptype(vtype).c_str());
	e=e+nd->name+" expected a "+ptype(vtype)+" but we get a "+ptype(nd->valtype)+'\n'; 
	return false;
}
void symcode::setboolean(Node*& b,ERRMSG& e)
{
	Expnode *nd=new Expnode(b,Expnode::INT);
	nd->valtype=1;
	b=nd;
}
void symcode::setnum(Node*& n,ERRMSG& e)
{
	Expnode *nd=new Expnode(n,Expnode::INT);
	nd->valtype=0;
	n=nd;
}
void symcode::traversal(Node*& nd,ERRMSG& e)
{
	if(nd->first && !isempty(nd->first))
		traversal(nd->first,e);
	if(nd->next && !isempty(nd->next))
		traversal(nd->next,e);

	if(isname(nd,"boolean"))
	{
		setboolean(nd,e);
		return;
	}
	if(isname(nd,"NUM"))
	{
		setnum(nd,e);
		return;
	}
	if(isname(nd,"var"))
	{
		setvar(nd,e);
		return;
	}
	if(isname(nd,"fcall"))
	{
		setfcall(nd,e);	
		return;
	}

	Expnode *expnode=NULL;
	vector<Node*> zip;
	unrolling(nd,zip);
	switch(zip.size())
	{
		case 1:
			if(isname(nd,"exp") || isname(nd,"term") 
					|| isname(nd,"primary") || isname(nd,"final") || isname(nd,"bexpressions")
					|| isname(nd,"bprimary") || isname(nd,"bterm"))
			{
				expnode=new Expnode(nd,Expnode::EXP);
				expnode->valtype=((Expnode*)zip[0])->valtype;
			}
			break;
		case 3:
			if(isname(zip[1],"OP"))
			{
				expnode=new Expnode(nd,Expnode::EXP);
				if(!check((Expnode*)zip[0],0,e) || !check((Expnode*)zip[2],0,e))
					return;
				expnode->valtype=0;
				nd=expnode;
				return;

			}	
			if(isname(zip[1],"AND") || isname(zip[1],"OR"))
			{
				expnode=new Expnode(nd,Expnode::EXP);
				if(!check((Expnode*)zip[0],1,e) || !check((Expnode*)zip[2],1,e))
					return;
				expnode->valtype=1;
				nd=expnode;
				return;
			}
			if(isname(zip[1],"compare_op"))
			{
				expnode=new Expnode(nd,Expnode::EXP);
				if(strcmp(zip[1]->first->str,"==")==0)
				{
					if(!check((Expnode*)zip[0],((Expnode*)zip[2])->valtype,e))
						return;
					//		fprintf(stderr,"Ctype:%d\n",((Expnode*)zip[2])->valtype);
					if(((Expnode*)zip[2])->valtype>1)
					{

						fprintf(stderr,"ERR:06\n");
						e=e+" Non-defination for '==' with type "+ptype(((Expnode*)zip[2])->valtype)+"\n";
					}
					expnode->valtype=1;
				}
				else
				{
					if(!check((Expnode*)zip[0],0,e)||!check((Expnode*)zip[2],0,e))
						return;
					expnode->valtype=1;
				}
				break;
			}

	}
	if(expnode==NULL)
		expnode=new Expnode(nd,(Expnode::NDTYPE)nd->type);
	nd=expnode;
	//	if(isname(nd,"final"))
	//		if(!check((Expnode*)nd,0,e))
	//			return;

	if(isname(nd,"bexpressions"))
		if(!check((Expnode*)nd,1,e))
			return;

	if(isname(nd,"print"))
		if(!(((Expnode*)zip[1])->valtype==0 || (((Expnode*)zip[1])->valtype==1)))
		{
			fprintf(stderr,"ERR:07,name:%s\n",zip[0]->name);
			e=e+" print requires BASIC integer/boolean, but get a "+ptype(((Expnode*)zip[1])->valtype)+"\n";
			return;
		}
	if(isname(nd,"assignment"))
		if(!check((Expnode*)zip[0],((Expnode*)zip[2])->valtype,e))
			return;

	if(isname(nd,"return"))
	{
		const SYMBOL *ptr=(symfunc*)(this);
		if(ptr->acc!=SYMBOL::ACCTYPE::FUNC)
		{

			//BUG
			fprintf(stderr,"ERR:08,acc:%d\n",((symfunc*)(this))->acc);
			e=e+" Expected a function but is "+'\n';
			return;
		}
		if(((Expnode*)zip[1])->valtype!=ptr->type)
		{
			//BUG
			fprintf(stderr,"ERR:09\n");
			e=e+"In "+ptr->name+" return type is not match\n";
			return;
		}
	}	
			

}	

void symprog::sem_declar(Node *ptr,string& st)
{
	Node *i=ptr->first,*j;
	while(!isempty(i))
	{
		//declar
		j=i->first;//1 of 3 types
		switch(j->name[0])
		{
			case 'f'://is a function
				add_func(j,program,st);	
				break;
			case 'c':
				add_class(j,st);
				break;
			case 'a':
				add_array(j,st);
				break;
		}
		i=i->next->first;
	}
}
symprog* semantic(bool pr)
{
	Node *ptr=syntax(0);
	symprog *prog=new symprog();
	prog->run(ptr,pr);				
	return prog;
}
