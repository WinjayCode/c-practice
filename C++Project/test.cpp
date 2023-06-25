// my first cpp file

// 预编译指令include,C++当中的预编译指令有好几种，除了include之外还有define、ifdef、undef等等。对于库函数我们需要首先查找到它对应的头文件，将其include之后再进行使用。
/*
* include这个指令会引入一个源代码文件，后面跟着的是一个包含文件名，也叫头文件名。
* C语言中的头文件以.h结尾，而C++当中兼容了C语言的头文件，只不过将其重新命名，去掉了末尾的.h，而换成了c开头。比如math.h文件替换成了cmath。
* iostream为C++的标准输入输出库，用来在终端读入或者打印文本信息。iostream可以拆开理解成io和stream，其中io表示input、output即输入输出，stream表示流，即使用流形式进行io。
*/
#include <iostream>

// 数学计算相关库，例如计算平方根的函数sqrt
#include <cmath>

// string类
#include<string>


// 命名空间是C++当中的特性，用来解决大型项目名称冲突的问题。
/*
* 有可能多个程序员同时开发了getValue函数，但当我们编译运行的时候，编译器无法知道我们究竟调用的是哪一个getValue，所以需要使用命名空间进行区分。
* 比如A程序员将getValue放入了名为A的命名空间当中，那么当我们调用getValue的时候就需要写成A::getValue，B程序员将它放入了名为B的命名空间中，同样调用的时候写成B::getValue。
* 然而常用的许多函数、变量都命名在std的命名空间当中，这就意味着当我们使用这类内容的时候，都需要在前面加上std::，比如标准输出的cout命令，需要写成std::cout。
* 这会导致编码变得繁琐，所以C++提供了using namespace的功能，即告诉编译器当前使用的命名空间名称，这样我们在调用该命名空间的内容时，可以省略前缀。
* 除了using namespace之外我们也可以单独使用using命令，例如：
* using std::cout;
* using std::cin;
*/
using std::cout;
using std::cin;
using namespace std;


// 函数命名
/*
* 函数命名同样遵循大驼峰命名法，即首字母以及每个单词首字母大写。
* 对于特殊的缩写单词，通常将它们视作是普通单词，而不会全部大写，如：
* void GetUrl(); // 正确
* void GetURL(); // 错误
*/


// 自定义函数
/*
* C++当中函数同样分为声明和实现，函数的声明一定要写在main函数之前，否则main函数在调用的时候将会找不到对应的函数，报错error: use of undeclared identifier。
* 所以一种正确的写法是在main函数之前写上函数的声明，函数的实现写在main函数之后。其实只需要保证函数声明在main函数之前即可，函数的实现并不限制摆放位置。
* 对于函数的声明，和变量的声明类似，它分为三个部分。分别是函数返回类型，函数名和函数所需的外界参数。
* 如果函数无需外界参数，也需要保留小括号。
* 另外在函数的声明当中，变量名也可以省略，只需要标注类型即可。
*/
void test();

int getResult(int, int);

int getValue(int x, int y);

int getValue(int x, int y) {
	return x + y;
}


void cout_p();
// 标准输出工具，可以将字符串输出在终端中。
/*
* cout本身是一个预定义的对象，它知道如何显示字符串、数字和单个字符。<<符号表示将字符串发送给cout，由cout输出在屏幕当中。<<符号表示了信息流动的路径，<<符号可以多个叠加连接，比如：
* cout << "hello" << "world"；
*/
// endl表示当前输出行的结束，cout遇到endl时会重启一行，否则则会接在同一行后面继续输出。
/*
* 除了使用endl之外，我们也可以使用换行符来达到同样的效果，如：
* cout << "hello" << "world\n";
*/
/*
* C++ Primer当中建议在输出由内容的字符串时使用换行符，而非endl，其他情况下使用endl，而非换行符。这两者绝大多数情况下是等价的，在一些特殊情况下可能会构成差异。
* 如endl确保程序继续运行前刷新输出，而使用"\n"则意味着有时候需要在输入信息之后才会出现提示。
*/
void cout_p() {
	// cout输出结果时可以通过多个<<符号进行拼接
	cout << "hello " << "c++" << endl;
}



void cin_p();
// cin顾名思义，表示读入，它可以从屏幕（终端）读入数据，流向我们指定的变量。
/*
* cin是输入数据的对象，数据从cin流向了wordCnt。即我们在终端输入的数据被读入到了wordCnt当中。
* 和cout一样，我们可以从终端读入多种类型的数据，如浮点数、整数、字符串等，cin会自动将读入的数据转化成对应的数据类型并完成赋值。
*/
void cin_p() {
	int wordCnt;
	int personCnt;
	int roomCnt;
	wordCnt = personCnt = roomCnt = 2;

	cout << "wordCnt=";
	cin >> wordCnt;

	cout << "word count: " << wordCnt << ", room count: " << roomCnt << endl;
}


void sqrt_p();
// 计算平方根
void sqrt_p() {
	double a = sqrt(9.0);
	cout << "a=" << a << endl;
}


void method_p();
// 函数
void method_p() {
	cout << "4+5=" << getValue(4, 5) << endl;
}


void sizeof_p();
// 当我们查看对象是变量类型时，需要使用括号，如果是变量本身，则括号是可选的。
void sizeof_p() {
	cout << "sizeof(int)=" << sizeof(int) << endl;
	int a = 6;
	cout << "sizeof int=" << sizeof a << endl;
}


void longlong__int64_p();
// long long 和 __int64
void longlong__int64_p() {
	long long a;
	scanf_s("%lld", &a);
	printf("long long = %lld\n", a);

	__int64 b;
	scanf_s("%I64d", &b);
	printf("__int64 = %I64d\n", b);
}


void char_p();
// char
void char_p() {
	char a = 'a';
	cout << "++a = " << ++a << endl;

	char b = 'b';
	cout << "--b = " << --b << endl;

	char c = '1';
	int num = c - '0';
	cout << "'1' - '0' = " << num << endl;

	char d = '1';
	if (d >= '0' && d <= '9') {
		cout << "1 is a number" << endl;
	}

	char e;
	cin.get(e);
	cout.put(e);

	//string str = "ten.gnehcnaib.c//:ptth";
	//for (int i = str.length() - 1; i >= 0; i--) {
	//	cout.put(str[i]);  //从最后一个字符开始输出
	//}
	//cout.put('\n');
}


void float_p();
// 浮点数类型
void float_p() {
	double a = 2.45e8; // 2.45*10^8
	double b = 1e-7; // 10^-7

	double epsilon = 1e-8;
	// 判断a和b是否相等
	if (abs(a - b) < epsilon) {
		cout << "a == b" << endl;
	} else {
		cout << "a != b" << endl;
	}

	float c = 2.3e22f;
	float d = c + 1.0f;

	cout << d - c << endl;
}


void calculate_p();
// 算术运算符
void calculate_p() {
	int a = 10, b = 3;

	cout << "10 + 3=" << a + b << endl;
	cout << "10 - 3=" << a - b << endl;
	cout << "10 * 3=" << a * b << endl;
	cout << "10 / 3=" << a / b << endl;
	cout << "10 % 3=" << a % b << endl;

	long long c = 0x3f3f3f3f3f3f3f;
	int d = a;
	cout << "long long:0x3f3f3f3f3f3f3f -> int=" << d << endl;

	// 允许低精度转高精度
	int e = 0x3f3f3f3f;
	long f = {e};
	cout << "int:0x3f3f3f3f -> long=" << f << endl;

	// 不允许高精度转低精度
	//long g = 2147483647999999999;
	//int h = {g};
	cout << "long:2147483647999999999 -> int=" << "Not Allowed" << endl;

	const int i = 55;
	char j = { i };
	cout << "const int 55 -> char=" << j << endl;

	//int k = 55;
	//char l = { k };
	cout << "int 55 -> char=" << "Not Allowed"<< endl;

	int m = 11.99 + 19.99;
	cout << "11.99 + 19.99=" << m << endl;

	int n = (int)11.99 + (int)19.99;
	cout << "(int)11.99 + (int)19.99=" << n << endl;
}


void str_p();
// 字符串
void str_p() {
	char str[5] = { 'h', 'e', 'l', 'l', 'o' };
	char str2[5] = { 'h', 'e', 'l', 'l', '\0' };
	cout << "{'h', 'e', 'l', 'l', 'o'}=" << str << endl;
	cout << "{'h', 'e', 'l', 'l', '\0'}=" << str2 << endl;

	char hello[6] = "hello";
	char world[] = "world";
	cout << hello << " " << world << endl;

	int a;
	char name[100];
	cin >> a;
	cin.get();
	cin.getline(name, 100);
	cout << "a=" << a << endl; 
	cout << "name=" << name << endl;
}


void cstring_h_p();
// 字符串函数
void cstring_h_p() {
	char str1[100]="hello world";
	char str2[100]="contact test";

	cout << "hello world" << endl;
	cout << "contact test" << endl;

	// 长度
	cout << "strlen=" << strlen(str1) << endl;

	// 拼接
	strcat_s(str1, str2);
	cout << "strcat=" << str1 << endl;

	// 有限拼接
	strncat_s(str1, str2, 4);
	cout << "strncat=" << str1 << endl;

	// 字符串拷贝
	strcpy_s(str1, str2);
	cout << "strcpy=" << str1 << endl;

	// 字符串有限拷贝
	strncpy_s(str1, str2, 4);
	cout << "strncpy=" << str1 << endl;

	// 字符串设置
	memset(str1, 'a', 100);
	cout << "memset=" << str1 << endl;

	int a[100];
	memset(a, 1, sizeof a);
	cout << "memset(int[] <- 1)=" << a << endl;

	memset(a, 0, sizeof a);
	cout << "memset(int[] <- 0)=" << a << endl;

	memset(a, -1, sizeof a);
	cout << "memset(int[] <- -1)=" << a << endl;

	memset(a, 0x7f, sizeof a);
	cout << "memset(int[] <- 0x7f)=" << a << endl;

	memset(a, 0x3f, sizeof a);
	cout << "memset(int[] <- 0x3f)=" << a << endl;

	// 字符串拷贝
	memcpy(str1, str2, 4);
	cout << "memcpy=" << str1 << endl;

	// 字符串比较
	char str3[100] = "abcd";
	char str4[100] = "abcd";
	int result = strcmp(str3, str4);
	int result2 = strncmp(str3, str4, 3);
	cout << "strcmp('abcd', 'abcd') = " << result << endl; // 0
	cout << "strncmp('abcd', 'abcd', 3) = " << result2 << endl; // 0

	// 字符位置查找
	char str5[100] = "abcd-efgh";
	char str6[100] = "-";
	char *result3 = strstr(str5, str6);
	cout << "strstr('abcd-efgh', '-') = " << result3 << endl; // -efgh
}



void string_p();
// 字符串
void string_p() {
	string str1 = { "hello world" };
	string str2 = "hello";
	string str3 { " world" };

	cout << "hello world[6]=" << str1[6] << endl;

	cout << "hello + world=" << str2 + str3 << endl;

	str2 += str3;
	cout << "hello += world=" << str2 << endl;

	cout << "hello world.size=" << str1.size() << endl;

	char a[100];
	cin.getline(a, 100);
	cout << "cin.getline=" << a << endl;

	string str4;
	getline(cin, str4);
	cout << "getline=" << str4 << endl;

	cout << "\"hello world\"" << endl;
	cout << R"(hello world)" << endl;
	cout << R"(hello 
	world)" << endl; // 换行
	cout << R"haha("(hello world)")haha" << endl;
}



void struct_p();
// 结构体
struct student {
	string name;
	int age;
	bool gender;
	double scores;
};
void struct_p() {
	student stu[2];
	stu[0] = {"mike", 10, 0, 98.8};
	stu[1] = {"jack", 20, 1, 99.9};
	cout << "struct student=" << stu[0].name << " " << stu[0].age << " " << stu[0].gender << " " << stu[0].scores << endl;
}



void enum_p();
// 枚举
enum color
{
	red = 3,
	blue = 1,
	orange,
	white,
	black
};
void enum_p() {
	color c = black;
	cout << "enum color {red=3, blue=1, orange, white, black}: black=" << c << endl;
}



void pointer_p();
// 指针
void pointer_p() {
	int a = 3;
	int* p = &a;
	cout << "int a = 3;  int* p = &a;" << endl;
	cout << "*p=" << *p << endl;
	cout << "p=" << p << endl << endl;

	*p = 5;
	cout << "*p = 5" << endl << endl;
	cout << "*p=" << *p << endl;
	cout << "p=" << p << endl;
}



// main函数是C++程序的入口函数，C++标准当中定义的main函数类型是int。返回0表示程序正常退出，所以一般我们要在main函数的最后写上return 0。
/*
* C++的main函数通常有两种写法，一种是参数留空，一种是定义参数数量以及参数值。
* int main() {}
* int main(int argc, char* argv[]) {}
*/
int main0() {
	int index = 0;
	cout << ++index << ".cout" << endl;
	cout << ++index << ".cin" << endl;
	cout << ++index << ".sqrt" << endl;
	cout << ++index << ".fuction" << endl;
	cout << ++index << ".sizeof" << endl;
	cout << ++index << ".long long/__int64" << endl;
	cout << ++index << ".char" << endl;
	cout << ++index << ".float" << endl;
	cout << ++index << ".calculate" << endl;
	cout << ++index << ".str" << endl;
	cout << ++index << ".cstring.h" << endl;
	cout << ++index << ".string" << endl;
	cout << ++index << ".struct" << endl;
	cout << ++index << ".enum" << endl;
	cout << ++index << ".pointer" << endl;
	cout << endl;

	cout << "num=" << endl << endl;
	int num;
	cin >> num;
	cout << endl;


	if (num == 1) {
		cout_p();
	}

	if (num == 2) {
		cin_p();
	}
	
	if (num == 3) {
		sqrt_p();
	}

	if (num == 4) {
		method_p();
	}
	
	if (num == 5) {
		sizeof_p();
	}
	
	if (num == 6) {
		longlong__int64_p();
	}
	
	if (num == 7) {
		char_p();
	}

	if (num == 8) {
		float_p();
	}

	if (num == 9) {
		calculate_p();
	}

	if (num == 10) {
		str_p();
	}

	if (num == 11) {
		cstring_h_p();
	}

	if (num == 12) {
		string_p();
	}

	if (num == 13) {
		struct_p();
	}

	if (num == 14) {
		enum_p();
	}

	if (num == 15) {
		pointer_p();
	}

	return 0;
}

// 变量规范
/*
* C++当中变量的声明由变量类型 + 变量名组成。
* 关于C++的命名有几种规则：
*	名称中只能使用字母、数字和下划线
*	名称的第一个字符不能是数字
*	大小写敏感
*	不能使用C++关键字（如class、void等）
*	用户自定义的标识符中不能连续出现两个下划线，也不能以下划线紧跟大写字母开头，此外定义在函数体外的标识符不能以下划线开头
*	C++对于名称长度没有限制，但部分平台有限制
* 总则:
*	总的原则是尽可能使用描述性的命名，不吝啬变量长度，因为相比之下让代码容易理解比容易敲出来更重要。
*/


// 类型命名
/*
* 类型命名采用大驼峰命名，不包含下划线，如：MyExcitingClass，HelloWorldClass等。
* 所谓类型命名包括类，结构体，类型定义（typedef），枚举，类型模板参数，它们均使用相同的约定。即大写字母开头，每个单词的开头也为大写，即大驼峰。
* 类和结构体：
* class UrlTable { ...
* class UrlTableTester { ...
* struct UrlTableProperties { ...
*
* 类型定义：
* typedef hash_map<UrlTableProperties *, string> PropertiesMap;
*
* using 别名
* using PropertiesMap = hash_map<UrlTableProperties *, string>;
*
* 枚举
* enum UrlTableErrors { ...
*/


// 变量命名
/*
* C++的变量没有像Java一样遵循小驼峰，而是一律小写，单词和单词之间以下划线连接。
* string table_name;  // 好 - 用下划线.
* string tablename;   // 好 - 全小写.
* string tableName;  // 差 - 混合大小写
*
* 但如果是类中的数据成员（成员变量），则变量的末尾需要额外的下划线：
* class TableInfo {
*	 ...
*	private:
*	 string table_name_;  // 好 - 后加下划线.
*	 string tablename_;   // 好.
*	 static Pool<TableInfo>* pool_;  // 好.
* };
*
* 但结构体除外，仍然和普通变量一样命名。
* struct UrlTableProperties {
*	string name;
*	int num_entries;
*	static Pool<UrlTableProperties>* pool;
* };
*/


// 常量命名
/*
* 声明为constexpr和const的变量，或者是其他没有显示定义但是在程序运行当中保持不变的，命名是以k开头，并且大小写混合，如：
* const int kDaysInAWeek = 7;
*/


// 声明变量
/*
* 在C++当中所有的变量都需要声明
* 我们声明了一个int类型的变量wordCnt，这样的语句会告诉编译器两个关键信息。一个是变量所需要的内存，一个是这块内存的名称。
* 比如在这个例子当中，我们声明了一个int型的变量。它占据32个二进制位，也就是4个字节，这块内存的名称被叫做wordCnt。
*	 int wordCnt;
*/


// 赋值语句
/*
* 变量被声明了之后，我们就可以通过赋值语句给它赋上我们想要的值。
*	wordCnt = 1;
*/


// 连续赋值的写法
/*
* int personCnt;
* int roomCnt;
* wordCnt = personCnt = roomCnt = 2;
*/


// 文件命名
/*
* 文件名全部要小写，可以包含下划线以及字符-，最好使用下划线。
*/


// 命名空间
/*
* 全部小写命名
*/


// 宏命名
/*
* 宏命名为全部大写，并且以下划线分割，如：
* #define ROUND(x) ..
* 不过不推荐在代码中使用宏。
*/


// 枚举命名
/*
* 与常量或宏一致，即kEnumName或ENUM_NAME。个人更倾向于后者。
*/


// 整形
/*
* 整型即整数，与小数对应。
* C++的基本整型有char、short、int、long，在C++ 11标准中，新增了long long。在部分编译器当中不支持long long，而支持__int64。
* 每一种类型都有有符号版本和无符号版本两种，所以总共一共有10种类型。
*/


// short、int、long和long long
/*
* 这四种类型都是整型，唯一的不同是范围的区别。受到底层硬件的影响，C++当中这四种类型的范围并不是固定的。由于要兼容各种不同类型的系统与硬件，所以没有办法对类型进行统一。
* 为了避免引起不便，C++提供了一种灵活的标准，它确保了每一种类型的最小范围。
*	short至少16位
*	int至少与short一样长
*	long至少32位，且至少与int一样长
*	long long至少64位，且至少与long一样长
*/


// 位与字节
/*
* 计算机内存的基本单元是位，英文是bit，音译成比特。一位bit只有0和1两个值，可以将其看成是开关。8位bit一共有256中不同的组合，即2^8=256。因此8位bit可以表示0-255或者-128-127。
* 每增加一个二进制位，可以表示的范围翻倍。因此16位可以表示65536个值，而32位可以表示4294672296个值，64位更大，大约能表示1.8*10^19。这个范围足够表示银河系中所有的星星。
* 8位二进制位是一个字节（byte），字节是计算机存储的最小计量单位。1024个字节称为1KB，而1024个KB又被称为1MB，1024MB为1GB。
* 一般在操作系统当中，都有最小长度，这通常是由CPU的位数所决定的。在常用的操作系统当中如Linux、Windows、MacOS，int和long为32位，short为16位，而long long为64位。
* 除了根据通常情况来推测之外，C++当中也提供了一些现成的工具来查看。比如sizeof函数，sizeof函数可以查看变量占据的字节数。
*	(这个函数既可以接受变量类型也可以接受变量本身，如果传入的是变量类型，那么计算的结果就是该类型的变量占据的内存大小，同理如果是变量本身，则表示变量本身占据的内存。)
* 除了sizeof函数之外，C++还提供了大量的常量。比如INT_MAX，LONG_MAX等，顾名思义这些常量的值就是各个类型的最大值。最小值，如INT_MIN，LONG_MIN等
*/


// 无符号类型
/*
* 比如8位二进制位既可以表示0-255也可以表示-128-127。这其实就是有符号和无符号的区别。
* 如果我们确定我们要存储的整数为非负数，并且想要拥有更大的范围，就可以使用无符号修饰符unsigned来修饰这几种类型。比如：
*	unsigned short ushort;
*	unsigned int uint;
*	unsigned long ulong;
*	unsigned long long ull;
*/


// long long 和 __int64
/*
* 在C++ Primer当中提到的64位的int只有long long，但是在实际各种各样的C++编译器当中，64位的int一直有两种标准。一种是long long，还有一种是__int64，非主流的VC甚至还支持_int64。
*/


// cin、cout和scanf、printf的选择问题
/*
* 这个问题对于C++开发工程师来说同样不是个问题，没有任何选择的必要，无脑用cin、cout就完事了。但对于算法竞赛玩家来说，这依然是一个要考虑的问题。
* 因为在算法竞赛当中，尤其是当数据量很大的时候，读入和输出占据的时间是非常可观的。看起来只是cin cout和scanf和printf的差别，但是两者的性能差异非常大。
* 关于性能差异的原因，主要有两种解释。一种解释是说cin为了与scanf混用，而不用担心指针混乱，加上了绑定，总是会与stdin保持同步。正是这一步操作消耗了大量的时间。同理，cout也会有类似的问题。
* 第二种解释是cout在输出之前会把要输出的内容先存入缓存区，中间多了一个步骤，也会带来性能的降低。
* 关于cin与stdin同步带来的开销，我们是有办法解决的，只需要在加上这一行代码：
*	std::ios::sync_with_stdio(false);
* 这行代码的意思是取消cin、cout与stdin、stdout的指针同步，会使得cin、cout的性能大大提升，达到和scanf、printf相差无几的程度。当然，更好的方法是使用scanf、printf代替。
*
* 而要使用scanf和printf又有一个问题，它们是C语言的标准输入输出方式，需要提供标识符来代表变量的类型，
* long long的标识符是lld，所以我们使用scanf读入一个long long类型的数写成：
*	long long a;
*	scanf("%lld", &a);
*
* __int64的标识符是I64d，注意这里是大写的i，不是l
*	__int64 a;
*	scanf("%I64d", &a);
*
*
* 变量定义	输出方式	gcc(mingw32)	g++(mingw32)	gcc(linux i386)	g++(linux i386)	MicrosoftVisual C++ 6.0
* long long	“%lld”	  错误				错误			正确			正确			无法编译
* long long	“%I64d”	  正确				正确			错误			错误			无法编译
* __int64	“lld”	      错误				错误			无法编译		无法编译		错误
* __int64	“%I64d”	  正确				正确			无法编译		无法编译		正确
* long long	 cout	      非C++				正确			非C++			正确			无法编译
* __int64	 cout	      非C++				正确			非C++			无法编译		无法编译
* long long	printint64()  正确				正确			正确			正确			无法编译
*/


// char类型
/*
* char的全称是character，也就是字符的意思。顾名思义，char类型是专门为了存储字符而设计的。
* 计算机存储数字非常方便，只需要将其转化成二进制即可。但存储字符就有点麻烦了，一般都是通过对字符进行数字化编码。这也就是为什么char类型本质上是另外一种整数，因为它存储的其实是字符的数字编码。
* char一共有8个二进制位，即一个字节，理论上能够存储256个字符。基本上足够涵盖计算机当中所有的字母、标点符号以及数字，即ASCII码。
* ASCII的全称是美国信息交换标准代码，它是一套电脑编码系统，包含了所有英文字母以及标点符号和一些特殊字符。全表一共有128个字符，刚好可以用一个char（有符号）来存储。
* 当我们把一个字符赋值给char型变量的时候，它会去查ASCII表，找到字符对应的编号。同样，当我们使用%c输出一个字符的时候，它也会去寻找char中存储的编码对应的符号进行输出。
* 既然字符在C++当中都是以数字的形式存储的，那么我们就可以对它来进行加减运算。比如：
*	char c = 'a';
*	cout << ++c << endl;
* 
* 得到的结果是'b'，有加自然也有减，我们也可以对它做减法操作。
*	char c = 'b';
*	cout << --b << endl;
* 
* 另外，我们还可以对于两个char类型的变量进行减法操作。比如用得比较多的就是将字符型的数字转成int型。
*	char c = '1';
*	int num = c - '0';
* 
* 我们还可以通过大于小于符号来判断char类型的范围：
*	char c = '1';
*	if (c >= '0' && c <= '9') {
*		cout << "c is a number" << endl;
*	}
*/


// getchar、putchar、cin.get、cout.put
/*
* getchar和putchar都是C语言当中专门面向字符IO的函数，也就是读入和输出字符的函数。
* 因为确定了处理的数据类型是字符，不需要额外的格式说明，因此getchar和putchar的效率要比scanf和printf更高。
* 所以在算法竞赛领域，有人为了提升程序的性能，丧心病狂地使用getchar代替scanf来读入数据。
* 我这里贴一段使用getchar来读入int型的代码，给大家做一个参考。这个属于标准的奇淫技巧，不推荐使用。
*	void read(int &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') {
        if (s == '-') {
            f = -1;
            s = getchar();
        }
    }
    while (s >= '0' && s <= '9') {
        x = x * 10 + s - '0';
        s = getchar();
    }
    x *= f;
	}
* 
* cin.get和cout.put与getchar和putchar的用法类似，只不过是C++当中的特性。大家可以参考一下下面这个例子，就不过多赘述了。
*	char c;
*	cin.get(c);
	cout.put(c);
*/


// 浮点数的使用
/*
* C++当中有两种浮点数的书写方式，第一种是使用常规的小数点表示法：
*	double a = 1.23;
*	float b = 3.43;
* 另外一种写法是科学记数法，写成：
*	double a = 2.45e8;
*	double b = 1e-7;
*/


// 浮点数类型
/*
* 和C语言一样，C++也有三种浮点数类型：float,double和long double。和整型一样，这三种类型都是浮点数，只不过表示的范围不同。
* 浮点数的范围有两个部分综合决定，一个部分是有效数字。比如14179是5位有效数字，而14000只有两位，因为后面三个0都是填充位，有效数字的位数不依赖小数点的位置。
* C++当中要求，float通常表示7位有效数字，double通常16位位，而long double至少和double一样。
* 另外，它们能够表达的指数范围至少是-37到37。一般来说，float一共是4个字节32位，而double是8个字节64位，当然这也取决于具体的运行环境。
* 
* 注意事项
* 关于浮点数的使用有几点注意事项，千万要注意。
*	1.cout输出浮点数会删除结尾的0
*	2.书写浮点数常量时默认为double类型，如果需要强制表示为float类型，请在结尾加上后缀f或者F，如：2.34f
*	3.由于浮点数有精度，不能直接判断两个浮点数是否相等，很有可能得不到预期结果，正确的做法是判断精度范围，如：
*		double epsilon = 1e-8;
*		// 判断a是否和b相等
*		if (abs(a - b) < epsilon) {
*			// todo
*		}
* 判断两个浮点数a和b是否相等，等价于两者的差的绝对值小于某一个精度。
*	4.范围问题，如运行下列代码将得到错误的结果：
*		float a = 2.3e22f;
*		float b = a + 1.0f;
*		cout << b - a << endl;
* 输出的结果将是0，因为2.3e22是一个小数点左边有23位的数字，加上1之后，就是在第23位加上1。但是float类型只能表示数字中的前6位或者前7位，表示不了这么高的精度，因此这个+1的操作完全没有生效。
* 这个问题是一个大坑，一不小心就会中招，千万要小心。
*/


// 算术运算符
/*
* C++当中提供5种基础的算术运算符：加法、减法、乘法、除法和取模。
* 前面三个都非常简单，着重讲下最后两种。
* 对于除法来说，我们要注意的是它是区分类型的。当我们的除数和被除数都是整数的时候，得到的结果也会是一个整数。
* 所以10 / 3得到的结果就是3，它的小数部分会被抛弃。想要得到小数结果，只需要除数或者被除数当中有一个是浮点型即可。
* 取模运算符求的就是一个数除以另外一个数之后的余数。这里要注意，在其他语言当中并没有对取模运算的限制，而在C++当中，严格限制了取模运算的对象只能是整数。否则编译的时候会报错。
* 
* 优先级
* C++当中算术运算符的优先级和我们从小数学课本里是一样的，先乘除再加减。
* 即当乘除法和加减法同时出现时，先算乘除后算加减。如果有多个运算符同样优先级，那么先左后右。
* 
* 类型转换
* 1.初始化和赋值时的转换
* 当我们对某个值进行初始化或者赋值的时候，C++会自动将赋予的值转化成接收者的类型。比如：
*	float a = 3.5f;
*	double b = a;
* 在上面这个例子当中，我们将一个float类型的变量a赋值给了double类型的b。那么编译器会将a的值拓展成64位的double再赋值给b。也就是说不会影响b的类型。
* 这样将长度更短的变量转化成更长变量的类型转换除了多占用一点内存之外，不会导致什么问题。但反向操作可能就会出错，比如：
*	long long a = 0x3f3f3f3f3f3f3f;
*	int b = a;
* 在上面的例子当中，我们将一个long long赋值给了int，由于a的数值非常大超过了int能够承载的范围，进行这样的赋值之后，编译器并不会报错（甚至不会有警告），但将会导致结果错误。b变量将不可能再和a变量相等。
* 再比如将float变量赋值给int的时候，同样也会有类似的问题，所以在进行赋值的时候，当两个变量的类型不同时，千万要当心。
* 
* 2.使用花括号进行转换
* 这是C++ 11的新特性，使用大括号进行初始化，这种操作被称为列表初始化。
* 这种方式的好处和坏处都很明显，好处是它不允许变量长度缩窄的情况，坏处则是又增加了学习的成本。
* 例如，不允许将浮点型转换成整型。在不同的整型之间以及整型转化成浮点型的操作可能被允许，取决于编译器知道目标变量能够正确地存储赋给它的值。比如可以将int类型赋值给long，因为long总是至少与int一样长，反向操作则会被禁止。
*	int a = 0x3f3f3f3f;
*	long b = {a};   // 允许
*
*	long a = 0x3f3f3f3f;
*	int b = {a};    // 禁止
* 关于列表初始化，C++ primer当中还列举了一个非常有意思的case：
*	const int x = 55;
*	char c = {x};   // 允许
*
*	int x = 55;
*	char c = {x}; // 禁止
*
*	const int x = 1255;
*	char c = {x};   // 禁止
*
*	const int x = 1255;
*	char c = x;  // 允许会警告
* 因为我们加了const修饰之后，编译器就明确知道了x的值，就等于55，它在char类型的范围内，所以允许将它转化成char。如果不加const，那么在编译器看来x是一个int型的变量，它的范围要大于char，所以会禁止。即使我们加了const修饰，如果x的值过大，超过char的范围，也同样会被禁止。
* 
* 3.表达式中转换
* 表达式时C++会将bool、char、unsigned char、signed char和short全部转换为int
* 对于bool类型来说，true会被转化成1，false转换成0，其他类型的转换应该都很好理解，都是将范围更小的变量转化成范围更大的int，这种转换称作整型提升。因为通常int类型都是计算机最自然的类型，也意味着计算机在处理int的时候，处理的速度最快。
* 将不同类型进行运算的时候，也会做一些转换。比如将int和float相加的时候，由于涉及到两种类型，其中范围较小的那个会被转换成较大的类型。比如如果我们计算9.0 / 5，那么编译器会先将5转化成5.0，再进行除法运算，这样得到的结果自然也是一个double。
* C++11的规范中除了一个类型转换的校验表，我们可以参考一下校验表理解一下类型转换的过程。
*	1.如果有一个数类型是long double，则将另外一个数也转成long double
*	2.否则，如果有一个数类型是double，则将另外一个数也转成double
*	3.否则，如果有一个数类型是float，则将另外一个数也转成float
*	4.否则说明所有操作数都是整数，执行整型提升
* 
* 4.强制类型转换
* 强制类型转换的方式有两种写法：
*	int a;
*	(long) a;
*	long (a);
* 这两行代码都是将一个int型的a转换成long型的，上面的是C语言的写法，底下一行是C++的写法
* 还有一点要注意就是转换的顺序，我们来看一个例子：
*	int a = 11.99 + 19.99;
*	cout << a << endl;
*	int b = int(11.99) + int(19.99);
*	cout << b << endl;
* 在这段代码当中a和b输出的结果是不同的，a输出的结果是31，而b是30。
* 这是因为第一行代码是先计算的加法，得到31.98，再通过类型转换将31.98转换成int。对于浮点数向整型的转换，C++会直接抹掉小数部分，所以得到的结果是31。而第二行代码当中，我们是先进行的类型转换，11.99和19.99分别被转换成了11和19，相加得到的结果也就是30了。
*/


// 数组
/*
* 数组其实也是一种数据格式，不过是一种复合类型，它可以存储多个同类型的值。
* 定义一个数组只需要三个要素：变量类型、数组名、数组长度即可。
*	typename arrayName[arraySize];
* 有一点需要注意，arrayName的类型不是数组，而是typename数组。也就是说数组也是区分类型的，这也是 C++中的数组和 Python 中 List 的区别之一。
* 
* 元素访问
* 对于一个数组来说，当我们需要访问其中的元素时，可以通过下标的方式来访问。
* 在绝大多数计算机程序当中，数组的下标通常都是从 0 开始的。第一个数存在第 0 位，第二个数存在第 1 位，以此类推。下标通过方括号表示，如：
*	cout << arrayName[0] << endl;
* 注意，我们传入的下标不能大于等于数组的长度（由于是从 0 开始的），编译器往往不会报错，只会给出一个警告，但运行的过程当中可能会引发各种意想不到的问题。因为很可能你访问的内存已经超过了程序管理的范围，访问到了一些操作系统内存或者是其他禁止访问的内存，引起难以想象的后果。
*	int a[3];
*	cout << a[10] << endl;
* 在上面的例子当中，我们声明了一个长度为 3 的数组，但是访问了下标 10。这显然超出了数组的范围，但是当我们编译的时候编译器并不会报错，只会抛出一个警告。要知道程序员往往是看不见警告的。
* 如果一不小心就会错过这个信息，导致潜在的风险。所以在访问之前一定要切记，确保下标在数组的范围内。
* 
* 初始化
* 数组和其他变量一样，也可以在声明的时候进行初始化。
* 最常见的方式是将它的每一个元素的值写出来：
*	int a[3] = {0, 1, 2};
* 编译器会将花括号当中的元素一个一个地填到数组对应的位置当中，花括号当中的元素数量并不一定需要和数组长度相等，如果小于数组长度，那么就会初始化对应数量的元素。
*	int a[3] = {0, 1};
* 那么数组 a 的前两位会被初始化成 0 和 1，其他的位置会被初始化为0。
* 如果想要将数组当中所有元素都初始化成 0，则比较特殊，我们只需要写一个 0 即可。
*	int a[100] = {0};
* 但只有初始化成 0 的时候可以这么操作，如果传入其他值，则不会生效。
* 还有一种初始化方式是我们不填数组的长度，而通过初始化的方式让编译器替我们去算：
*	int a[] = {0, 1, 2, 3, 4};
* 编译器通过执行初始化知道 a 数组的长度为 5，不过 C++ primer 强烈建议我们不用这么干。因为我们人工数出来的结果可能和编译器不一样（我们会犯错），增加我们 debug 的难度。
* 
* C++11 的初始化方式
* C++11 当中对于数组的初始化又有了一些新的定义，首先是可以省略等号：
*	int a[3] {1, 2, 3};
* 其次花括号内可以留空，这等价于将元素全部设置为 0：
*	int a[100] = {};
*	int b[10] {};
* 列表初始化时禁止缩窄转化，我们在上一篇文章当中讲过：
*	char cs[4] = {0, 0x3f3f3f3f, 'a', 'z'};  // 禁止，因为0x3f3f3f3f超过了char范围
*/


// 字符串
/*
* 定义
* 字符串就是连续的一连串字符，在C++当中， 处理字符串的方式有两种类型。一种来自于C语言，也被称为C风格字符串。另外一种是基于string类库。
* C风格的字符串其实就是字符存储在char数组当中。不过它和一般的数组有一些区别，拥有一些特殊的性质。比如以空字符\0结尾，它的ascii码是0，用来标记字符串的结尾。
*	char str[5] = {'h', 'e', 'l', 'l', 'o'};
*	char str2[5] = {'h', 'e', 'l', 'l', '\0'};
* 对于上面的两个例子，第一个例子虽然也是char数组，但是由于它的结尾不是\0，所以它不能看成是字符串。因为很多算法都是以\0的位置为标记的，比如计算字符串长度的算法，以及cout等等。
* 上面我们采用的是数组常规的初始化方式，这当然是可以的，不过这样会很不方便。一个是需要一位一位地填写字符，会非常地麻烦。另外还需要手动填充\0，也容易忘记，所以对于字符串而言我们还有更好的初始化方式：
*	char hello[6] = "hello";
*	char world[] = "world";
* 用引号括起来的字符串隐式地包含了结尾的\0，需要注意的是，我们在确定数组长度的时候需要将结尾的\0也计算在内。
* 这里要提醒大家注意引号的区别， 在C++当中单引号表示单个字符，而双引号表示字符串。所以下面这种写法是错误的：
*	char c = "S";
* 并且“S”其实表示的是字符串所在的内存地址，当我们把一个内存地址赋值给一个char类型的时候自然就会报错了。
* 
* 字符串的读入
* 直接用字符串常量来初始化字符数组只是一种方式，另外一种常用的方式是只定义字符数组的长度，从外部读入数据，如：
*	char str[100];
*	scanf("%s", str);
*	cin >> str;
* 无论是使用scanf还是cin，都是一样的效果。
* 但是没有这么简单，比如我们再来看一段代码：
*	char name[100];
*	char level[100];
*	scanf("%s", name);
*	scanf("%s", level);
* 在这段代码当中，我们定义了name和level两个字符串变量。当我们执行的时候，就会发现问题：
* 刚输入完名字，还没来得及输level就结束了。如果我们把name和level分别输入的话（str1 str2）就会发现，name的值是str1，level的值是str2。
* 这说明了什么？说明了我们读入字符串的时候它并不是按行读入的，而是按照空格分隔的！它不像是隔壁的Python，input默认就是读入一行，C++的读入默认都是按照空格分隔的。
* 那问题来了，假如我们需要读入一行应该怎么办呢？也有办法，我们可以使用cin.getline代替之前的scanf或者是cin。我们来看下它的函数签名：
*	istream& getline ( istream& is, string& str, char delim );
*	istream& getline ( istream& is, string& str );
* C++允许参数列表不同的同名函数重载，这两个签名都是OK的。两者的差别在于第三个参数，但三个参数表示分隔符，如果不传的话，默认是'\n'。第二个参数表示字符串的长度，所以如果要按照行来读入字符串的话，刚刚的代码应该写成：
*	cin.getline(name, 100);
*	cin.getline(level, 100);
* 除了可以使用getline之外，还可以使用get。get有好几种变体，一种变体是读入一个字符，它有一种变体也可以读入一行字符串。不过唯一的区别是，get函数不会处理行尾的换行符。如果我们要读入两行字符的话，需要手动将这个换行符处理掉。
*	cin.get(name, 100); // 读入一行数据
*	cin.get();   // 读入换行符
*	cin.get(level, 100);// 读入第二行数据
* 写成三行看起来有些繁琐，我们还可以进行简化，简化成一行：
*	cin.get(name, 100).get().get(level, 100);
* 看起来很像是Java8的流式编程，能够这样做的原因是get和getline函数会返回一个cin的对象。所以我们可以这样连续调用。
* 相信有些同学已经注意到了，同样的函数名，根据我们传入的参数不同执行了不同的逻辑。这在C++当中叫做函数重载，是一个非常重要的概念。
* 
* 关于getline有一个比较大的坑，当我们同时使用cin和getline的时候，有时候会出现问题。比如下面这段代码：
*	int a;
*	char name[100];
*	cin >> a;
*	cin.getline(name, 100);
*	cout << "a = " << a << endl;
*	cout << "name = " << name << endl;
* 这段代码很简单，我们定义了两个变量。一个是int型的a，一个是字符串name。我们使用cin读入a，使用getline读入name。
* 这看起来一点问题也没有，但是当我们运行的时候就会出现问题。会发现我都没有来得及输入name，程序就结束了，而name读到了一个空。
* 这并不是C++有bug，而是我们在输入32的时候，敲了一个回车。所以在使用getline读入一行的时候，看到了回车，直接退出了，读入了一个空行，这就是为什么我们没有机会输入name的原因。
* 要解决这个问题怎么办呢？其实也很简单，我们额外读入一个字符，把换行符给读取掉就行了。
*	int a;
*	char name[100];
*	cin >> a;
*	cin.get(); // getchar() C语言版本
*	cin.getline(name, 100);
*	cout << "a = " << a << endl;
*	cout << "name = " << name << endl;
*/



//字符串函数
/*
* cstring.h库即C语言中的string.h库，它是C语言中为字符串提供的标准库。C++对此进行了兼容，所以我们在C++当中一样可以使用。
* 
* strlen
* 由于编译器是按照\0的位置来确定字符串的结尾的，所以字符串的长度并不等于数组的长度。我们可以使用strlen函数求得字符串的真实长度
* 
* strcat
* strcat函数可以将两个字符串进行拼接，它的函数签名为：
*	char *strcat(char *dest, const char *src)
* 我们可以看到它接受两个参数，一个是dest，一个是src，都是char*类型，返回的结果也为char *类型。在C++当中，数组名是指向数组中第一个元素的常量指针。所以虽然签名中写的参数是指针类型，但我们传入数组名同样可以。
* 我们传入两个字符串之后，strcat函数会将src字符串拼接在dest字符串末尾，并且返回指向拼接之后结果的指针。
* 
* strncat
* strcat函数的变种，函数额外多接收一个参数控制拷贝src字符串的最大长度。
*	char *strncat(char *dest, const char *src, size_t n)
* 
* strcpy
* 字符串拷贝函数，可以将src字符串中的内容复制到dest。
*	char *strcpy(char *dest, const char *src)
* 有两点需要注意:
* 1.如果dest字符串长度不够长，在编译时不会报错，但运行时可能导致问题。
* 2.如果dest中原本就有内容，会被覆盖。
* 
* strncpy
* strcpy加入长度限制的版本，可额外多传入一个参数n表示最多赋值n个字符。当src长度小于n时，剩余部分将会使用空字节填充。
* 
* memset
* 字符串的批量设置函数，可以将字符串批量设置成某一个字符。
*	void *memset(void *str, int c, size_t n)
* int c表示要被设置的字符，size_t n表示设置的字符数量。
* memset除了可以用来给字符串进行批量设置之外也可以给int型的数组进行批量设置。由于一个32位的int占据4个字节，也就是4个字符长度。所以使用memset进行批量设置的时候，最终得到的结果将是4个传入的int c拼接的结果。
*	int a[100];
*	memset(a, 1, sizeof a); // memset(a, 1, 400); 因为一个int占据4个字节
* 我们这样设置之后，a数组当中的元素并不是1，而是0x01010101,转成10进制是16843009。所以使用memset对int型数组进行初始化一般只用3种操作：
*	// 1. 批量设置成0
*	memset(a, 0, sizeof a);
*	// 2. 批量设置成-1
*	memset(a, -1, sizeof a);
*	// 3. 批量设置成一个接近最大整数上限的值
*	memset(a, 0x7f, sizeof a);
*	memset(a, 0x3f, sizeof a);
* 
* memcpy
* 和strcpy类似，从str2中复制N个字符到str1中。
*	void *memcpy(void *str1, const void *str2, size_t n)
* 
* strcmp
* 将两个字符串按照字典顺序进行比较，对于字典序的顺序定义为：两个字符串自左向右逐个字符相比（按 ASCII 值大小相比较），直到出现不同的字符或遇 \0 为止。
*	int strcmp(const char *str1, const char *str2)
* 返回的结果为一个int，如果它小于0，说明str1小于str2，如果它等于0，说明两者相等，如果大于0，说明str1大于str2。
* 
* strncmp
* strcmp长度限制版，可以额外接受一个数字n，表示最多比较长度为n的字符。
* 
* strstr
*	char *strstr(const char *haystack, const char *needle)
* 在haystack中搜索needle第一次出现的位置，返回指向该位置的指针。
* 
* strtok
* 
* memmove
*/


// string类
/*
* 和char *的异同
* 在C++当中，除了char *类型，还有专门的字符串类型，就叫做string。通过包含头文件string就可以使用：
*	include<string>
* 在很多方面，string类型的使用方法和char *一样，例如：
*	string str1;
*	string str2 = "hello world"; // 初始化和char *一致
*	cout << str2 << endl; // cout和char *一致
*	cout << str[2] << endl; // 元素访问和char *一致
* 除此之外，它还有一个更大的好处，就是当我们从外界读入字符串的时候，再也不用操心读入的字符串超界的问题了。因为string类设计可以让程序自动处理字符串的大小。
* 
* C++11初始化
* 我们也可以使用C++11的列表初始化特性在string上，不过其实没必要，直接使用等于号赋值更方便一些：
*	string str1 = {"hello world"};
*	string str2 {"test"};
* 
* 拼接
* 在使用char *的时候，如果我们要拼接两个字符串，需要调用函数strcat来实现。而有了string，我们可以直接使用加号来拼接两个字符串：
*	string str1 = "hello";
*	string str2 = "world";
*	string str3 = str1 + str2;
* 不仅如此，还可以使用+=，表示把另外一个字符串添加在自己末尾：
*	str1 += str2; // 等价于str1 = str1 + str2
* 
* 长度
* 对于char *的字符串，我们要求长度，需要使用strlen函数。而string类型的字符串，我们可以直接调用.size()函数：
*	string str = "hello";
*	cout << str.size() << endl; // output 5
* 
* IO
* string类的cin和cout用法都和char *完全一致，不过在读取一行的时候有些区别。
*	char st[100];
*	cin.getline(st, 100);
* 
*	string str;
*	getline(cin, str);
* 对于char *来说，我们调用的cin.getline表示的是cin中的一个方法。而后者，我们调用的getline传入了cin，这里的cin是一个传入的参数，并且也没有指定长度，因为string会自动设定长度。
* 
* 原始字符串
* 关于string类型，C++11有一个原始字符串的新特性。
* 在字符串表示当中，当我们要添加一些特殊字符的时候，往往需要在前面加上反斜杠，表示取义。当这类字符多了之后，就会很麻烦：
*	cout << "i want to output \"hello world\"" << endl;
* 如果我们要换行，还要在其中加入\n。针对这个问题C++11提出了原始字符串，也就是说在原始字符串当中所有的符号都会被原本原样地输出，不需要再使用\来取义了。
* 原始字符串以"R(开头)"结尾，`比如刚才的内容就可以写成：
*	cout << R"(i want to output "hello world")" << endl;
* 但是有一个小问题，假如我们想要输出的结果当中也包含"(该怎么办呢？也有办法，编译器允许我们在"和(之间加入任意的字符来做区分（空格、左括号、右括号、斜杠、控制字符除外），这样我们在结尾的时候，也需要加上同样的字符。例如：
*	cout << R"tst("(test)")tst" << endl;
* 运行之后，屏幕上会输出"(test)"的结果。
*/



// 结构体
/*
* 定义结构体
* 数组可以存储多个同类型的变量，但如果我们想要存储多个不同类型的变量呢？比如说我们想要存储一个学生的姓名、年龄、性别、考试分数，这些变量可能string, int, float都有，显然就不能使用数组了。
* 为了满足这样的存储要求，我们可以使用C++当中的结构体（struct）。在同一个结构体当中，我们可以定义许多种不同类型的变量，就可以满足我们各种各样的需求了。如果我们想要存储多个这样的内容，还可以将它定义成数组。
* 结构体和类已经很接近了，所以理解结构体对于理解面向对象非常有帮助。虽然算法竞赛当中一般用不到面向对象，但是对于开发者来说，面向对象可以说是必学的内容。C++ primer中说，结构体是C++ OOP（面向对象编程）的基石。
* 我们使用关键字struct来定义一个结构体：
*	struct student {
*		string name;
*	    bool gender;
*	    double scores;
*	};
* 
* 表示定义了一个结构体，它的类型名是student，花括号当中括起来的内容是结构体的成员变量。注意student是类型名，也就是说我们可以用它来定义出student类型的变量：
*	student xiaoming;
*	student john;
* 
* 我们可以用.来访问结构体内部的元素：
*	cout << john.name << endl;
* 
* struct的定义有两种写法，既可以写在main函数外部，也可以写在main函数内部。如：
*	// 写法1
*	struct student {
*		string name;
*	    bool gender;
*	    double scores;
*	};
*
*	int main() {
*	    // do something
*	    return 0;
*	}
*
*	// 写法2
*	int main() {
*	    struct student {
*	        string name;
*	        bool gender;
*	        double scores;
*	    };
*	    // do something
*	    return 0;
*	}
* 逻辑上两种方式完全一样，只是第一种方式student类型可以被任何函数使用，但如果写在main函数内部，就只能在main函数内部使用。
* 结构体变量也可以定义在函数内部定义，定义在外部的变量被所有函数所共享，也就是全局变量。C++ primer当中提倡尽量使用外部结构体。
* 
* 初始化方式
* 我们可以和数组一样，在花括号内使用逗号进行分隔，如：
*	student xiaoming = {"xiaoming", 1, 3.5};
* 编译器会按照顺序，分别将"xiaoming"赋值给name，1赋值给gender，3.5赋值给score。我们也可以使用C++11的列表初始化方式省略掉中间的等于号：
*	student xiaoming {"xiaoming", 1, 3.5};
* 
* 结构体数组
* 定义了结构体之后，我们还可以像是基础变量类型一样定义结构体数组。
*	struct student {
*		string name;
*	    bool gender;
*	    double scores;
*	};
*	student sts[10];
* 
* 对于结构体数组来说，我们也可以使用列表初始化方式来初始化，由于结构体本身的初始化就用到花括号，所以数组的初始化会使用到花括号的嵌套，像是这样：
*	student sts[2] = {
*	    {"xiaoming", 1, 3.6},
*	    {"john", 1, 5.2}
*	};
*/



// 枚举
/*
* 简介
* C++当中提供了枚举操作，我们可以使用enum关键字创建枚举类型。
* 这种方式创建的为符号常量，可以代替const关键字，并且还可以自定义名字，让代码可读性更强。如：
*	enum color {red, blue, orange, white, black};
* 在这一句语句当中完成两件事，首先我们创建了一个新的变量类型叫做color，这是一个枚举类型。其次我们创建了一些符号常量，例如red,bule,orange这些。在默认状态下，会将这些枚举量赋值为整数，第一个枚举量red为0，第二个blue为1，以此类推。
* 当然我们也可以显示地给这些枚举量赋值，如：
*	enum color {red=3, blue=1, orange, white, black};
* 这样前面给定了数值的red和blue会按照我们给定的值进行赋值，而之后从orange开始，依次赋值成2，3，4.
* 
* 使用
* 我们定义了枚举类型之后，可以当做正常类型来进行声明：
*	color a;
* 由于color是一个枚举类型，所以当我们赋值的时候，只能赋值列举出来的类型，如果附上其他的值可能会出问题。根据编译器的不同出现的结果也不一样，有些编译器会报错，有些则只会给出警告。不管是报错还是警告，我们都不应该这么做：
*	color a = red; // OK
*	color a = 10; // 报错或警告
* 由于enum底层存储的是整型，所以有一些奇怪的操作是允许的，但是也强烈不建议这么做，也可能会有很大的风险。比如：
*	cout << (red < blue) << endl; // 比较大小
*	cout << blue - red << endl; // 做加减法
*	int c = red + 3; // 赋值给int
* 这些操作在语法上都是允许的，但非常不推荐这么干，因为没有意义。枚举型当中每一个类型都有各自的逻辑含义，是不能拿来做计算的。虽然语法上可行，但逻辑上没有意义。
* 我们也可以使用强制转换将整型转成枚举类型：
*	color c = color(3);
* 但同样不推荐，因为有可能数字3对应的枚举量并不存在，这也不会报错，但也许会影响程序的正确性。
* 
* 枚举值的取值范围
* 前文说了，只有声明中的枚举值是有效的，然而由于C++允许使用强制转换转换成枚举值，所以理论上枚举值取值范围内的值都可以被转换成枚举值，虽然这些值在逻辑上不一定有意义。
* 对于枚举变量来说，它的范围并不是固定的，而是根据定义情况波动的。C++会根据枚举值声明的情况计算上限和下限，只能允许在范围内的整型值强制转化为枚举值。
*	enum flag {black = 1, white = 2, red = 23};
* C++采取的是最小长度的方式，比如说我们上面定义的枚举值最大的是23，它会计算出大于23的最小2的幂，也就是32。所以这个枚举值的上限就是31，对于下限也会采用类似的计算，如果定义的最小值大于等于0，那么它的下限就是0，否则采取同样的算法，只不过加上负号。
* 之所以会如此复杂，也是为了尽可能地节省内存空间。毕竟很多C++程序的运行环境都是单片机或者是芯片，内存并不充裕。
*/



// 指针
/*
* 指针初探
* 前言
* 首先要明确的是指针是一个变量，它特殊的点在于虽然同样是变量，它存储的并不是值，而是一个内存地址。内存地址顾名思义就是存放在内存当中的位置，对于非指针的变量， 我们也可以使用&操作符去获取它的地址。这就是为什么我们使用scanf在读取变量的时候，需要在变量名之前加上一个&符号。
*	int a;
*	scanf("%d", &a);
* 目的就是为了将a变量的地址传给scanf函数，从而将屏幕当中读取到的内容填写到a变量对应的地址当中。
* 我们也可以直接输出一个变量的地址，但输出结果是一个十六进制的数，代表一个内存位置。如果大家学过汇编或者是了解过底层的话，应该不陌生。这个输出的结果是给机器看的，人类无法读懂。
*	int a;
*	cout << &a << endl;
* 
* 声明和初始化
* 指针和普通变量不同，它存储的值是地址。所以在声明指针的时候，也会有一点细小的区别。我们通过*符号创建指针，*运算符称为间接值(indirect value)或解除引用(dereferencing)，现在理解这两个概念可能有些费劲，没关系我们可以先放一放。只许看记住使用*创建指针即可，*写在类型和变量名中间，如：
*	int * p;
* 这样我们就创建了一个int型的指针，它的名字叫做p。关于*的位置，有些人喜欢紧跟着变量类型，有些人喜欢紧跟着变量名。其实都可以，看个人喜好。传统上来说C程序员喜欢后者，突出ptr是一个指针。
*	int *ptr;
* C++程序员更喜欢前者，突出是一个int型的指针：
*	int* ptr;
* 这两种都可以，对于编译器来说没有任何区别。但是要注意的是，每一个指针变量都需要一个*：
*	int a, *ptr;
* 前面说了，由于指针的值是一个地址，所以我们在对指针进行初始化或者赋值的时候，就需要用到取地址符。
*	int a = 3;
*	int *p = &a; // 获取了a的地址
* 当我们有了指针变量之后，我们可以使用*来访问它指向的内存地址的值。
*	int a = 3;
*	int *p = &a;
*	cout << *p << endl; //output: 3
* 要注意的是，由于指针p指向a的地址，所以当我们通过*符号修改了p指向的值之后，a的值一样会发生变化。
*	*p = 5;
*	cout << a << endl; //output: 5
* 正因为指针有这样的特性，所以使用的时候千万小心……
*/