 #include <iostream>
 #include <string>
 #include <time.h>
 using namespace std;

 string chooseWord();
 bool contains(string word, char ch);
 void renderGame(string guessedWord, int badGuessCount);
 char readAGuess();
 string update(string guessedWord, string secretWord, char guess);

 int main() {
    string secretWord = chooseWord();
    string guessedWord = string(secretWord.length(), '-');
    int badGuessCount = 0;

    const int MAX_BAD_GUESSES = 7; //Số lần được phép đoán sai
    do {
        renderGame(guessedWord, badGuessCount); //hiển thị giá treo trước khi bắt đầu game
        char guess = readAGuess();
        if (contains(secretWord, guess)) //kiểm tra xem chữ người chơi đoán có đúng không
            guessedWord = update(guessedWord, secretWord, guess);
        else badGuessCount++;
    } while (badGuessCount < MAX_BAD_GUESSES && secretWord != guessedWord); //khi chưa vượt số lần đoán sai & ng chơi đoán chưa đúng

    renderGame(guessedWord, badGuessCount);

    if (badGuessCount < MAX_BAD_GUESSES) cout << "Congratulations! You win!";
    else cout << "You lost. The correct word is " << secretWord;
 }

//Máy chọn từ
    const string WORD_LIST[] = {"angle", "ant", "apple", "arch", "arm", "army",
     "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry", "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
     "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
     "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
     "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
     "cow", "cup", "curtain", "cushion",
     "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
     "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
     "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
     "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
     "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
     "leaf", "leg", "library", "line", "lip", "lock",
     "map", "match", "monkey", "moon", "mouth", "muscle",
     "nail", "neck", "needle", "nerve", "net", "nose", "nut",
     "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
     "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
     "rail", "rat", "receipt", "ring", "rod", "roof", "root",
     "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
     "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
     "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
     "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
     "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
     "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
     };
    const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
    string chooseWord(){
     srand(time(0)); //Để không lặp lại từ đã chọn
     int randomIndex = rand() % WORD_COUNT;
     return WORD_LIST[randomIndex];
    }

//Người chơi đoán chữ
   char readAGuess(){
        cout <<"Your guess: ";
        char g;
        cin >> g;
        return g;
    }

//Vẽ hình, hiển thị
    const string FIGURE[] = {
             " ------------- \n"
             " | \n"
             " | \n"
             " | \n"
             " | \n"
             " | \n"
             " ----- \n",
             " ------------- \n"
             " | | \n"
             " | \n"
             " | \n"
             " | \n"
             " | \n"
             " ----- \n",
             " ------------- \n"
             " | | \n"
             " | O \n"
             " | \n"
             " | \n"
             " | \n"
             " ----- \n",
             " ------------- \n"
             " | | \n"
             " | O \n"
             " | | \n"
             " | \n"
             " | \n"
             " ----- \n",
             " ------------- \n"
             " |  | \n"
             " |  O \n"
             " | /| \n"
             " | \n"
             " | \n"
             " ----- \n",
             " ------------- \n"
             " |  | \n"
             " |  O \n"
             " | /|\\ \n"
             " | \n"
             " | \n"
             " ----- \n",
             " ------------- \n"
             " |  | \n"
             " |  O \n"
             " | /|\\ \n"
             " | / \n"
             " | \n"
             " ----- \n",
             " ------------- \n"
             " |  | \n"
             " |  O \n"
             " | /|\\ \n"
             " | / \\ \n"
             " | \n"
             " ----- \n",
            };
    void renderGame(string guessedWord, int badGuessCount){
        cout << FIGURE[badGuessCount] << endl;
        cout << guessedWord << endl;
        cout << "Number of wrong guesses: " << badGuessCount << endl;
    }

//Kiểm tra chữ người chơi đoán có đúng không
    bool contains(string word, char ch){
        return (word.find(ch) != std::string::npos);
    }

//Cập nhật trạng thái: từ đã đoán, từ đoán sai
    string update(string guessedWord, string secretWord, char guess){
    for (int i = secretWord.length() - 1; i >= 0; i--) {
         if (secretWord[i] == guess) {
         guessedWord[i] = guess;
         }
     }
     return guessedWord;
    }

