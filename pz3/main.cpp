#include <gtest/gtest.h>
#include <string>
#include <vector>


using namespace std;

class Container{
public:
	string name = "";
	int rackId = 0;

	Container(){

	};
	Container(string _name, int _rackId = 0) : name(_name), rackId(_rackId){};

	void setName(string _name){
		name = _name;
	} 

	void setRackId(int _rackId){
		rackId = _rackId;
	}
};

struct ContainerTest : testing::Test{
	Container *container;

	ContainerTest(){
		container = new Container;
	}

	~ContainerTest(){
		delete container;
	}
};

TEST_F(ContainerTest, ContainerEmpty){
	EXPECT_EQ("", container->name);
}

TEST_F(ContainerTest, ContainerName){
	container->setName("container1");
	EXPECT_EQ("container1", container->name);
}

TEST_F(ContainerTest, ContainerRackId){
	container->setRackId(2);
	EXPECT_EQ(2, container->rackId);
}

TEST(ContainerVector, ContainerPush){
	vector<Container> vContainer;
	Container cont1;
	Container cont2;
	vContainer.push_back(cont1);
	vContainer.push_back(cont1);
	EXPECT_EQ(2, vContainer.size());
}

TEST(ContainerVector, ContainerPop){
	vector<Container> vContainer;
	Container cont1;
	Container cont2;
	vContainer.push_back(cont1);
	vContainer.push_back(cont1);
	vContainer.pop_back();
	EXPECT_EQ(1, vContainer.size());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}