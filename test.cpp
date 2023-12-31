/*#include "main.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "Student.cpp"
#include "helperFuncs.cpp"

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

/*
TEST_CASE("BST Insert", "[flag]"){
        std::ostringstream oss;
		AVLTree tree;   // Create a Tree object
		tree.insert("Jacob", "12345678");
		tree.insert("John", "23456789");
		tree.insert("Flop", "00000001");
        tree.printInorder(oss);
		string expectedOutput = "Flop, Jacob, John\n";
		REQUIRE(oss.str() == expectedOutput);
	    REQUIRE(1 == 1);
}

TEST_CASE("Incorrect Commands", "[flag]") {
        std::ostringstream oss;
        AVLTree tree;
        tree.insert("A11y", "45679999", oss);
        tree.removeInorder(6, oss);
        tree.insert("Ben", "9", oss);
        tree.remove("99999", oss);
        tree.search("24242424", oss);
        string expectedOutput = "unsuccessful\nunsuccessful\nunsuccessful\nunsuccessful\nunsuccessful\n";
        REQUIRE(oss.str() == expectedOutput);

}
TEST_CASE("Edge Cases", "[flag]") {
    std::ostringstream oss;
    //Taken from stack overflow for test cases https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
    string expectedOutput;
    std::streambuf* coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    AVLTree tree;
    tree.insert("Alex", "45679999");
    tree.insert("Ben", "44444444");
    tree.remove("77777777");
    tree.search("99999999");
    tree.removeInorder(10);
    expectedOutput = "successful\nsuccessful\nunsuccessful\nunsuccessful\nunsuccessful\n";
    std::cout.rdbuf(coutBuf);
    REQUIRE(oss.str() == expectedOutput);
}

TEST_CASE("Rotations R-R", "[flag]") {
    std::ostringstream oss;
    //Taken from stack overflow for test cases https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
    string expectedOutput;
    std::streambuf *coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    AVLTree tree;
    tree.insert("Alex", "11111111");
    tree.insert("Ben", "22222222");
    tree.insert("Chang", "33333333");
    tree.printPreorder();
    expectedOutput = "successful\nsuccessful\nsuccessful\nBen, Alex, Chang\n";
    std::cout.rdbuf(coutBuf);
    REQUIRE(oss.str() == expectedOutput);
}

TEST_CASE("Rotations L-L", "[flag]") {
    std::ostringstream oss;
    //Taken from stack overflow for test cases https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
    string expectedOutput;
    std::streambuf *coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    AVLTree tree;
    tree.insert("Chang", "33333333");
    tree.insert("Ben", "22222222");
    tree.insert("Alex", "11111111");
    tree.printPreorder();
    expectedOutput = "successful\nsuccessful\nsuccessful\nBen, Alex, Chang\n";
    std::cout.rdbuf(coutBuf);
    REQUIRE(oss.str() == expectedOutput);
}

TEST_CASE("Rotations R-L", "[flag]") {
    std::ostringstream oss;
    //Taken from stack overflow for test cases https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
    string expectedOutput;
    std::streambuf *coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    AVLTree tree;
    tree.insert("Alex", "11111111");
    tree.insert("Chang", "33333333");
    tree.insert("Ben", "22222222");
    tree.printPreorder();
    expectedOutput = "successful\nsuccessful\nsuccessful\nBen, Alex, Chang\n";
    std::cout.rdbuf(coutBuf);
    REQUIRE(oss.str() == expectedOutput);
}

TEST_CASE("Rotations L-R", "[flag]") {
    std::ostringstream oss;
    //Taken from stack overflow for test cases https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
    string expectedOutput;
    std::streambuf *coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    AVLTree tree;
    tree.insert("Chang", "33333333");
    tree.insert("Alex", "11111111");
    tree.insert("Ben", "22222222");
    tree.printPreorder();
    expectedOutput = "successful\nsuccessful\nsuccessful\nBen, Alex, Chang\n";
    std::cout.rdbuf(coutBuf);
    REQUIRE(oss.str() == expectedOutput);
}

TEST_CASE("Deletion No Child", "[flag]") {
    std::ostringstream oss;
    //Taken from stack overflow for test cases https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
    string expectedOutput;
    std::streambuf *coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    AVLTree tree;
    tree.insert("Chang", "33333333");
    tree.insert("Alex", "11111111");
    tree.insert("Ben", "22222222");
    tree.remove("11111111");
    tree.printPreorder();
    expectedOutput = "successful\nsuccessful\nsuccessful\nsuccessful\nBen, Chang\n";
    std::cout.rdbuf(coutBuf);
    REQUIRE(oss.str() == expectedOutput);
}

TEST_CASE("Deletion One Child", "[flag]") {
    std::ostringstream oss;
    //Taken from stack overflow for test cases https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
    string expectedOutput;
    std::streambuf *coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    AVLTree tree;
    tree.insert("Alex", "11111111");
    tree.insert("Ben", "22222222");
    tree.remove("22222222");
    tree.printPreorder();
    expectedOutput = "successful\nsuccessful\nsuccessful\nAlex\n";
    std::cout.rdbuf(coutBuf);
    REQUIRE(oss.str() == expectedOutput);
}
TEST_CASE("Deletion Two Child", "[flag]") {
    std::ostringstream oss;
    //Taken from stack overflow for test cases https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
    string expectedOutput;
    std::streambuf *coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    AVLTree tree;
    tree.insert("Alex", "11111111");
    tree.insert("Ben", "22222222");
    tree.insert("Chang", "33333333");
    tree.remove("22222222");
    tree.printPreorder();
    expectedOutput = "successful\nsuccessful\nsuccessful\nsuccessful\nChang, Alex\n";
    std::cout.rdbuf(coutBuf);
    REQUIRE(oss.str() == expectedOutput);
}
TEST_CASE("Large Insert and Deletion", "[flag]") {
    std::ostringstream oss;
    //Taken from stack overflow for test cases https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
    std::streambuf *coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    //taken from stack overflow https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(10000000, 99999999);
    std::vector<pair<string,string>> expectedOutput;
    std::vector<std::string> names = {
            "Khaleesi",
            "Raphael",
            "Kailey",
            "Danny",
            "Emberly",
            "Jerry",
            "Aliya",
            "Kyle",
            "Thalia",
            "Thatcher",
            "Charlee",
            "Alec",
            "Harlee",
            "Davis",
            "Amina",
            "Kashton",
            "Jordyn",
            "Fabian",
            "Esther",
            "Arturo",
            "Natalia",
            "Sean",
            "Briella",
            "Damon",
            "Alessandra",
            "Kai",
            "Lia",
            "Orion",
            "Wynter",
            "Jamir",
            "Brynleigh",
            "Dayton",
            "Viviana",
            "Brodie",
            "Phoebe",
            "Enzo",
            "Remington",
            "Alvaro",
            "Avah",
            "Roberto",
            "Denise",
            "Jeremias",
            "Adelyn",
            "Emory",
            "Jessie",
            "Eliseo",
            "Amber",
            "Foster",
            "Madison",
            "Charlie",
            "Amalia",
            "Jesus",
            "Colette",
            "Waylon",
            "Lillie",
            "Conrad",
            "Brooklynn",
            "Maxwell",
            "Reina",
            "James",
            "Journi",
            "Dion",
            "Gia",
            "Roger",
            "Harper",
            "Wilson",
            "Samara",
            "Vihaan",
            "Flora",
            "Kendrick",
            "Raina",
            "Jared",
            "Camryn",
            "Azariah",
            "Alejandra",
            "Ian",
            "Willa",
            "Patrick",
            "Eileen",
            "Aaron",
            "Persephone",
            "Gianni",
            "Romina",
            "Anthony",
            "Persephone",
            "Carter",
            "Keilani",
            "Zachariah",
            "Jessica",
            "Camden",
            "Anya",
            "Lance",
            "Magnolia",
            "Kasen",
            "Aliyah",
            "Jeffery",
            "Myra",
            "Harley",
            "Amina",
            "Cillian",
            "Magnolia"
    };
    string out;
    AVLTree tree;
    for(int i = 0; i < 100; i++)
    {
        int randomInput = distr(gen);
        pair<string, string> temp;
        temp.first = to_string(randomInput);
        temp.second = names[i];
            expectedOutput.push_back(temp);
            out += "successful\n";
            tree.insert(names[i], to_string(randomInput));
    }
    sort(expectedOutput.begin(), expectedOutput.end());
    std::uniform_int_distribution<int> distro(0,99);
    for (int i = 0; i < 10; i++) {
        int randomNum = distro(gen);
        tree.remove(expectedOutput[randomNum].first);
        out += "successful\n";
        expectedOutput.erase(expectedOutput.begin() + randomNum);
    }
    for (int i = 0; i < expectedOutput.size(); i++) {
        out += (expectedOutput[i].second + ", ");
    }
    out = out.substr(0,out.length()-2);
    out += "\n";
    tree.printInorder();
    std::cout.rdbuf(coutBuf);
    REQUIRE(oss.str() == out);
}
 */