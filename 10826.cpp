#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;

class inf_int
{
private:
	void Add(const char, const unsigned int);
	char* digits;
	unsigned int length;
	bool thesign;   // true if positive , false if negative.
					// ex) 15311111111111111 -> digits="1111 1111 1111 1135 1", length=17, thesign=true;
					// ex) -12345555555555 -> digits="5555 5555 5543 21", length=14, thesign=false
					// you may insert additional private members here.

public:
	inf_int();               // assign 0 as a default value
	inf_int(int);
	inf_int(const char*);
	inf_int(const inf_int&); // copy constructor
	~inf_int(); // destructor

	inf_int& operator=(const inf_int&); // assignment operator

	friend bool operator==(const inf_int&, const inf_int&);
	friend bool operator!=(const inf_int&, const inf_int&);
	friend bool operator>(const inf_int&, const inf_int&);
	friend bool operator<(const inf_int&, const inf_int&);

	friend inf_int operator+(const inf_int&, const inf_int&);
	friend inf_int operator-(const inf_int&, const inf_int&);
	friend inf_int operator*(const inf_int&, const inf_int&);
	// friend inf_int operator/(const inf_int& , const inf_int&); // not required

	friend std::ostream& operator<<(std::ostream&, const inf_int&);
	// friend istream& operator>>(istream& , inf_int&);    // not required
};

inf_int::inf_int()
{
	this->digits = new char[2];	// �����Ҵ�

	this->digits[0] = '0';		// default �� 0 ����
	this->digits[1] = '\0';
	this->length = 1;
	this->thesign = true;
}

inf_int::inf_int(int n) {
	char buf[100];

	if (n<0) {		// ���� ó��
		this->thesign = false;
		n = -n;
	}
	else {
		this->thesign = true;
	}

	int i = 0;
	while (n>0) {			// ���ڸ� ���ڿ��� ��ȯ�ϴ� ����
		buf[i] = n % 10 + '0';

		n /= 10;
		i++;
	}

	if (i == 0) {	// ������ ������ 0�� ���
		new (this) inf_int();	// ������ ��ȣ��...gcc���� �����Ͽ����� �ִٰ� ��. inf_int()�� ��� ������ �ν��Ͻ��� ������. 
	}
	else {
		buf[i] = '\0';

		this->digits = new char[i + 1];
		this->length = i;
		strcpy(this->digits, buf);
	}
}

inf_int::inf_int(const char* str)
{
	std::string s(str);
	if (s[0] == '-') {
		thesign = false;
		s.erase(s.begin() + 0);
	}
	else {
		thesign = true;
	}

	std::reverse(s.begin(), s.end());
	length = s.length();
	const char* temp_str = s.c_str();
	digits = new char[length + 1];
	strcpy(digits, temp_str);

}

inf_int::inf_int(const inf_int& source) {
	this->digits = new char[source.length + 1];

	strcpy(this->digits, source.digits);
	this->length = source.length;
	this->thesign = source.thesign;
}

inf_int::~inf_int() {
	delete digits;		// �޸� �Ҵ� ����
}

inf_int& inf_int::operator=(const inf_int& source)
{
	if (this->digits) {
		delete this->digits;		// �̹� ���ڿ��� ���� ��� ����.
	}
	this->digits = new char[source.length + 1];

	strcpy(this->digits, source.digits);
	this->length = source.length;
	this->thesign = source.thesign;

	return *this;
}

bool operator==(const inf_int& source, const inf_int& dest)
{
	if (!strcmp(source.digits, dest.digits) && (source.thesign == dest.thesign)) {
		return true;
	}

	return false;
}

bool operator!=(const inf_int& source, const inf_int& dest)
{
	return !operator==(source, dest);
}

bool operator>(const inf_int& left, const inf_int& right)
{
	bool is_left_abs_big = false;
	//same
	if (operator==(left, right)) {
		return false;
	}

	//absolute value
	if (strlen(left.digits) > strlen(right.digits)) {
		is_left_abs_big = true;
	}
	else if (strlen(left.digits) == strlen(right.digits)) {
		int idx = strlen(left.digits);

		while (idx--) {
			int abs_judge = left.digits[idx] - right.digits[idx];
			if (abs_judge > 0) {
				is_left_abs_big = true;
				break;
			}
			else if (abs_judge == 0) {
				continue;
			}
			else {
				is_left_abs_big = false;
				break;
			}
		}
	}

	//sign
	if (left.thesign == right.thesign) {
		if (left.thesign == 0) {
			return !is_left_abs_big;
		}
		else {
			return is_left_abs_big;
		}
	}
	else {
		if (left.thesign == 1) {
			return is_left_abs_big;
		}
		else {
			return !is_left_abs_big;
		}
	}
}

bool operator<(const inf_int& left, const inf_int& right)
{
	if (operator>(left, right) || operator==(left, right)) {
		return false;
	}
	else {
		return true;
	}
}


inf_int operator+(const inf_int& a, const inf_int& b)
{
	inf_int c;
	unsigned int i;

	if (a.thesign == b.thesign) {	// ������ ��ȣ�� ���� ��� + �����ڷ� ����
		for (i = 0; i<a.length; i++) {
			c.Add(a.digits[i], i + 1);
		}
		for (i = 0; i<b.length; i++) {
			c.Add(b.digits[i], i + 1);
		}

		c.thesign = a.thesign;

		return c;
	}
	else {	// ������ ��ȣ�� �ٸ� ��� - �����ڷ� ����
		c = b;
		c.thesign = a.thesign;

		return a - c;
	}
}


inf_int operator-(const inf_int& source, const inf_int & dest)
{
	inf_int left(source);
	inf_int right(dest);

	if (left == right) {
		return inf_int(0);
	}

	std::string str_normal;
	std::string str_complement;
	bool sign_flag = false;
	//+ - + (+a-b)
	if (source.thesign == 1 && dest.thesign == 1) {
		//���������� ū ���� �� ���, �ڸ��� �ٲٰ�, ���߿� ��ȣ ����
		if (operator<(left, right)) {
			right = source;
			left = dest;
			sign_flag = true;
		}
		std::string str_normal = left.digits;
		std::string str_complement = right.digits;

		//�ڸ��� ����
		int len_abs = abs((int)(str_normal.length() - str_complement.length()));
		for (int i = 0; i < len_abs; i++) {
			str_complement += '0';
		}

		//10�Ǻ��� �����
		for (int i = 0; i < str_complement.length(); i++) {
			str_complement[i] = '9' - str_complement[i] + '0';
		}
		str_complement[0]++;

		reverse(str_complement.begin(), str_complement.end());
		reverse(str_normal.begin(), str_normal.end());

		inf_int a(str_complement.c_str());
		inf_int b(str_normal.c_str());
		inf_int result = a + b;

		//������������ ���� �ڸ��� ����
		std::string cut(result.digits);
		reverse(cut.begin(), cut.end());
		cut.erase(cut.begin());

		for (int i = 0;;) {
			if (cut[i] == '0') {
				cut.erase(cut.begin());
			}
			else if (cut[i] != '0') {
				break;
			}
		}

		inf_int ret(cut.c_str());
		//���������� ū ���� ���� ��쿴����, ��ȣ�� �ٲ��ش�.
		if (sign_flag) {
			ret.thesign = false;
		}
		return ret;
	}

	//(-a+b) = -(+a-b)
	//- - - �̰��� -�� +�� ���ϴ� �� --> +���� -�� ���ϴ� ��
	if (source.thesign == 0 && dest.thesign == 0) {
		right = source;	left = dest;
		left.thesign = 1;
		right.thesign = 1;
		inf_int ret = left - right;

		return ret;
	}

	//(+a+b)
	//+ - -
	if (source.thesign == 1 && dest.thesign == 0) {
		right.thesign = 1;
		inf_int ret = left + right;
		ret.thesign = 1;
		return ret;
	}

	//(-a-b) = -(a+b)
	//- - +
	if (source.thesign == 0 && dest.thesign == 1) {
		left.thesign = 1;
		inf_int ret = left + right;
		ret.thesign = 0;
		return ret;
	}
}

inf_int operator*(const inf_int& cand, const inf_int& plier)
{
	inf_int mulcand = cand;
	inf_int mulplier = plier;
	inf_int result(0);
	mulcand.thesign = true;
	mulplier.thesign = true;

	for (int i = 0; i < strlen(cand.digits); i++) {
		int pluscnt = cand.digits[i] - '0';
		for (int i = 0; i < pluscnt; i++) {
			result = result + mulplier;
		}
		std::string plier_plus_0(mulplier.digits);
		if (strcmp(plier_plus_0.c_str(), "0")) {
			plier_plus_0 = "0" + plier_plus_0;
		}
		std::reverse(plier_plus_0.begin(), plier_plus_0.end());
		mulplier = *(new inf_int(plier_plus_0.c_str()));
	}

	if (cand.thesign ^ plier.thesign) {
		result.thesign = false;
	}

	if (!strcmp(result.digits, "0")) {
		result.thesign = true;
	}

	return result;
}


std::ostream& operator<<(std::ostream& out, const inf_int& source)
{
	int i;

	if (source.thesign == false) {
		out << '-';
	}
	for (i = source.length - 1; i >= 0; i--) {
		out << source.digits[i];
	}
	return out;
}

void inf_int::Add(const char num, const unsigned int index)	// a�� index �ڸ����� n�� ���Ѵ�. 0<=n<=9, ex) a�� 391�϶�, Add(a, 2, 2)�� ����� 411
{
	if (this->length<index) {
		this->digits = (char*)realloc(this->digits, index + 1);

		if (this->digits == NULL) {		// �Ҵ� ���� ����ó��
			std::cout << "Memory reallocation failed, the program will terminate." << std::endl;
			exit(0);
		}

		this->length = index;					// ���� ����
		this->digits[this->length] = '\0';	// �ι��� ����
	}

	if (this->digits[index - 1]<'0') {	// ���� ���� '0'���� ���� �ƽ�Ű���� ��� 0���� ä��. �������� �ʾҴ� ���ο� �ڸ����� ��� �߻�
		this->digits[index - 1] = '0';
	}

	this->digits[index - 1] += num - '0';	// �� ����


	if (this->digits[index - 1]>'9') {	// �ڸ��ø��� �߻��� ���
		this->digits[index - 1] -= 10;	// ���� �ڸ������� (�ƽ�Ű��) 10�� ����
		Add('1', index + 1);			// ���ڸ��� 1�� ���Ѵ�
	}
}
/*
int main()
{
	std::string a;
	std::string b;
	cin >> a >> b;
	inf_int aa(a.c_str());
	inf_int bb(b.c_str());
	cout << (aa + bb);


	return 0;
}
*/
typedef vector<vector<inf_int> > matrix;

matrix operator* (const matrix &a, const matrix &b) {
	int n = a.size();
	matrix c(n, vector<inf_int>(n));
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			for (int k = 0; k<n; k++) {
				c[i][j] = c[i][j]+ (a[i][k] * b[k][j]);
			}
		}
	}
	return c;
}

int main() {
	LL n;
	cin >> n;
	vector<inf_int> v(10001);
	v[0] = inf_int(0);
	v[1] = inf_int(1);
	for (int i = 2; i < 10001; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	cout << v[n];
	return 0;
}