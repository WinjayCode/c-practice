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


// 自定义函数
/*
* C++当中函数同样分为声明和实现，函数的声明一定要写在main函数之前，否则main函数在调用的时候将会找不到对应的函数，报错error: use of undeclared identifier。
* 所以一种正确的写法是在main函数之前写上函数的声明，函数的实现写在main函数之后。其实只需要保证函数声明在main函数之前即可，函数的实现并不限制摆放位置。
* 对于函数的声明，和变量的声明类似，它分为三个部分。分别是函数返回类型，函数名和函数所需的外界参数。
* 如果函数无需外界参数，也需要保留小括号。
* 另外在函数的声明当中，变量名也可以省略，只需要标注类型即可。
*/
void test();
int getValue(int x, int y);
int getResult(int, int);


int getValue(int x, int y) {
	return x + y;
}

// 函数命名
/*
* 函数命名同样遵循大驼峰命名法，即首字母以及每个单词首字母大写。
* 对于特殊的缩写单词，通常将它们视作是普通单词，而不会全部大写，如：
* void GetUrl(); // 正确
* void GetURL(); // 错误
*/


// main函数是C++程序的入口函数，C++标准当中定义的main函数类型是int。返回0表示程序正常退出，所以一般我们要在main函数的最后写上return 0。
/*
* C++的main函数通常有两种写法，一种是参数留空，一种是定义参数数量以及参数值。
* int main() {}
* int main(int argc, char* argv[]) {}
*/ 
int main() {
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
	cout << "hello c++" << endl;

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
	*/
	int wordCnt;

	// 赋值语句
	/*
	* 变量被声明了之后，我们就可以通过赋值语句给它赋上我们想要的值。
	*/
	wordCnt = 10;

	// 连续赋值的写法
	int personCnt;
	int roomCnt;
	wordCnt = personCnt = roomCnt = 10;

	// cin顾名思义，表示读入，它可以从屏幕（终端）读入数据，流向我们指定的变量。
	/*
	* cin是输入数据的对象，数据从cin流向了wordCnt。即我们在终端输入的数据被读入到了wordCnt当中。
	* 和cout一样，我们可以从终端读入多种类型的数据，如浮点数、整数、字符串等，cin会自动将读入的数据转化成对应的数据类型并完成赋值。
	*/
	cin >> wordCnt;

	// cout输出结果时可以通过多个<<符号进行拼接
	cout << "word count: " << wordCnt << ", room count: " << roomCnt << endl;


	// 计算平方根
	double a = sqrt(10.0);
	cout << "a=" << a << endl;

	cout << "3+5=" << getValue(3, 5) << endl;



	// 当我们查看对象是变量类型时，需要使用括号，如果是变量本身，则括号是可选的。
	cout << sizeof(int) << endl;
	int b = 3;
	cout << sizeof b << endl;

	return 0;
}

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