#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
// #include "utils.h"
// #include "pieces.h"
#include "function.h"
#include <iostream>
#include <fstream>
using namespace sf;
using namespace std;

int main()
{
    const char title[] = "Flappy Bird";
    srand(time(0));
    RenderWindow window(VideoMode(350, 480), title);
    Texture obj1 , obj2 , obj3 , obj4;

    obj1.loadFromFile("img/bird.png");
    obj2.loadFromFile("img/blue1.png");
    obj3.loadFromFile("img/birdup.png");
    obj4.loadFromFile("img/piller.png");

    Font font_score;
    font_score.loadFromFile("img/open-sans/OpenSans-Bold.ttf");
    Text game_score;
    game_score.setFont(font_score);
    game_score.setPosition(170,20);
    game_score.setCharacterSize(30);
    game_score.setFillColor(Color::Black);

    Sprite bird(obj1) , background(obj2) , birdup(obj3) , pillar(obj4);

    Clock clock;
    float timer = 0;
    float delay = 0.1;
    bool flap = false;
    bool gamebreak = false;
    int newgrid[20][16] = {0};
    bool hit_pillar = false;
    int score  = 0;
    string score_str;

    while(window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        Event e;
        while (window.pollEvent(e))
        {                                // Event is occurring - until the game is in running state
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close();
        }
        
        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            flap = true;
        }
        if(x < 0)
            flap = false;

        //------------------------------------------------------------------------------------

        fallbird(delay , timer , flap , newgrid , score);

        gamebreak =  gamelose();
        if(gamebreak == true)
        {
            break;
        }
        hit_pillar = hitpillar();
        if(hit_pillar == true)
        {
            birdfall();
        }

        //------------------------------------------------------------------------------------
        score_str = to_string(score);
        game_score.setString(score_str);
        


        window.clear(Color::Black);
        window.draw(background);


        for(int i = 0 ; i < M ; ++i)
        {
            for(int j = 0 ; j < N ; ++j)
            {
                if(gamegrid[i][j] == 0)
                    continue;
                pillar.setTextureRect(IntRect(gamegrid[i][j] * 10 , 30 , 40 , 20));
                pillar.setPosition(j *20, i * 20);
                pillar.move(0,0);
                window.draw(pillar);    
            }
        }

          for(int i = 0 ; i < M ; ++i)
        {
            for(int j = 0 ; j < N ; ++j)
            {
                if(gamegrid2[i][j] == 0)
                    continue;
                pillar.setTextureRect(IntRect(gamegrid2[i][j] * 10 , 30 , 40 , 20));
                pillar.setPosition(j *20, i * 20);
                pillar.move(0,0);
                window.draw(pillar);    
            }
        }
       

        if(flap == true)
        {
            birdup.setPosition(y * 20,x * 20);
            birdup.move(0,0);
            window.draw(birdup);
        }
        else
        {
            bird.setPosition(y * 20,x * 20);
            bird.move(0,0);
            window.draw(bird);
        }
        flap = false;
        window.draw(game_score);



        
        window.display();
    }

    return 0;
}
