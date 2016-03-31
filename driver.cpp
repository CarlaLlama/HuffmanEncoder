/**
*.cpp Huffman Encoding Driver File
* Carla Wilby 31/03/2016
*/
using namespace std;


int main(int argc, char* argv[])
{
	string prefix;
	string outfile;
	int img_no;
	int bytes_no;
	string operation_message;

	if(argc < 2){
		cout << "Incorrect program entry." << endl;
		cout << "Correct usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name] [-g i output_file_name]" << endl;
		return 0;
	}

	// Make volimage Object, read in images
	VolImage volimg;
	prefix = string(argv[1]);
	volimg.readImages(prefix);
