#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace sf;
using namespace std;
int main()
{
	RenderWindow window(VideoMode(1280, 720), "Hit Ball");
	window.setFramerateLimit(60);

	//image
	Image img;
	if (!img.loadFromFile("images\\blur.jpg"))
	{
		cout << "Image Error";
	}
	Texture texture;
	texture.loadFromImage(img);
	Sprite sprite;
	sprite.setTexture(texture);

	int c1 = 0, c2 = 0;

	Text Player1, Player2;
	Font f;
	f.loadFromFile("FontFile.ttf");
	Player1.setString(to_string(c1));
	Player1.setFont(f);
	Player1.setFillColor(Color::White);
	Player1.setPosition(560, 38);

	Player2.setString(to_string(c2));
	Player2.setFont(f);
	Player2.setPosition(650, 38);
	Player2.setFillColor(Color::White);

	//second image
	Image img1;
	if (!img1.loadFromFile("images\\start.jpg"))
	{
		cout << "Image Error";
	}
	Texture texture1;
	texture1.loadFromImage(img1);
	Sprite sprite1;
	sprite1.setTexture(texture1);

	// last image 
	Image img3;
	if (!img3.loadFromFile("images\\blur.jpg"))
	{
		cout << "Image Error";
	}
	Texture texture3;
	texture3.loadFromImage(img3);
	Sprite sprite3;
	sprite3.setTexture(texture3);

	Texture ScoreBoard;
	ScoreBoard.loadFromFile("ScoreBoard.png");
	Sprite TScore(ScoreBoard);
	TScore.setPosition(350, 20);
	//-------------------------------------------------------

	// ins1
	Image ins1;
	if (!ins1.loadFromFile("images\\ins1.png"))
	{
		cout << "ins1 error";
	}
	Texture t_ins1;
	t_ins1.loadFromImage(ins1);
	Sprite s_ins1;
	s_ins1.setTexture(t_ins1);
	s_ins1.setOrigin(-100, -430);

	// ins2
	Image ins2;
	if (!ins2.loadFromFile("images\\ins2.png"))
	{
		cout << "ins2 error";
	}
	Texture t_ins2;
	t_ins2.loadFromImage(ins2);
	Sprite s_ins2;
	s_ins2.setTexture(t_ins2);
	s_ins2.setOrigin(-1000, -380);

	//Ball
	Texture ball;
	ball.loadFromFile("Ball.png");
	Sprite Ball(ball);
	Ball.setPosition(640, 560);
	//------------------------------------------------------

	// font
	Font font;
	if (!font.loadFromFile("FontFile.ttf"))
	{
		cout << "Error";
	}
	Text text;
	text.setFont(font);
	text.setString("Press ENTER To Start");
	text.setCharacterSize(70);
	text.setFillColor(Color::White);
	text.setOrigin(-500, -400);
	text.setStyle(Text::Bold | Text::Underlined);
	text.setOutlineColor(Color(0, 0, 0, 128));

	// text 
	Text text2;
	text2.setFont(font);
	text2.setString("Exit Game");
	text2.setCharacterSize(70);
	text2.setFillColor(Color::White);
	text2.setOrigin(-500, -500);
	text2.setStyle(Text::Bold | Text::Underlined);
	text2.setOutlineColor(Color(0, 0, 0, 128));

	//LOSER text
	Font font1;
	if (!font1.loadFromFile("FontFile.ttf"))
	{
		cout << "Error";
	}
	Text Gover;
	Gover.setFont(font1);
	Gover.setString("LOSER!");
	Gover.setCharacterSize(70);
	Gover.setFillColor(Color::White);
	Gover.setOrigin(-530, -480);
	Gover.setStyle(Text::Bold | Text::Underlined);
	Gover.setOutlineColor(Color(0, 0, 0, 128));

	// music
	Music music;
	SoundBuffer sb;
	if (!music.openFromFile("ice_cave.ogg"))
		return -1;
	if (!sb.loadFromFile("finish.wav"))
		return -1;
	Sound m;
	m.setBuffer(sb);
	int dx = 0, dy = 0;
	float Yspeed = 0;
	bool bl = true;
	//----------------------------------------------------

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
				{
					window.clear();
					RenderWindow window1(VideoMode(1280, 720), "Hit Ball2");
					window1.setFramerateLimit(60);
					int basex = 640;
					while (window1.isOpen())
					{
						Event event1;
						while (window1.pollEvent(event1))
						{
							if (event1.type == Event::Closed)
							{
								window1.close();
							}
							if (event1.type == Event::KeyPressed)
							{
								if (event1.key.code == sf::Keyboard::Escape)
								{
									window1.close();
								}
							}

							//animation
							if (event1.type == Event::Closed)
							{
								window1.close();
							}
							if (Keyboard::isKeyPressed(Keyboard::Key::Left))
							{
								s_ins2.move(-10.0f, 0.0f);
							}
							else if (Keyboard::isKeyPressed(Keyboard::Key::Right))
							{
								s_ins2.move(10.0f, 0.0f);
							}
							else if (Keyboard::isKeyPressed(Keyboard::Key::Up))
							{
								s_ins2.move(0.0f, -10.0f);
							}
							else if (Keyboard::isKeyPressed(Keyboard::Key::Down))
							{
								s_ins2.move(0.0f, 10.0f);
							}
							//---------------------------------------------
							if (Keyboard::isKeyPressed(Keyboard::Key::A))
							{
								s_ins1.move(-10.0f, 0.0f);
							}
							else if (Keyboard::isKeyPressed(Keyboard::Key::D))
							{
								s_ins1.move(10.0f, 0.0f);
							}
							else if (Keyboard::isKeyPressed(Keyboard::Key::W))
							{
								s_ins1.move(0.0f, -10.0f);
							}
							else if (Keyboard::isKeyPressed(Keyboard::Key::S))
							{
								s_ins1.move(0.0f, 10.0f);
							}

						}
						//ball
						FloatRect blobbyBox1 = s_ins1.getGlobalBounds();
						FloatRect blobbyBox2 = s_ins2.getGlobalBounds();
						FloatRect ballBox = Ball.getGlobalBounds();
						if (Ball.getPosition().y <= 0 || Ball.getPosition().y + Ball.getGlobalBounds().height >= window1.getSize().y)
						{
							dy = !dy;
						}
						if (Ball.getPosition().x <= 0 || Ball.getPosition().x + Ball.getGlobalBounds().width >= window1.getSize().x)
						{
							dx = !dx;
						}
						if (blobbyBox1.intersects(ballBox))
							dx = !dx, Yspeed = rand() % 10;
						if ( blobbyBox2.intersects(ballBox))
							dx = !dx;


						if (bl)
						{
							if (dx == 0)
								Ball.move(-10.f, dy == 0 ? Yspeed : -Yspeed);
							else
								Ball.move(10.f, dy == 0 ? Yspeed : -Yspeed);
						}

						//Check ball position
						if (Ball.getPosition().x >= 1160 && Ball.getPosition().y >= 300 && Ball.getPosition().y <= 560) 
						{
							c1++;
							Ball.setPosition(basex, Ball.getPosition().y);
							if (c1 == 5)
							{
								RenderWindow window2(VideoMode(1280, 720), "Hit Ball3");
								window2.setFramerateLimit(60);
								while (window2.isOpen())
								{
									Event ev;
									while(window2.pollEvent(ev))
									{
										if (ev.type == Event::Closed)
										{
											window2.close();
											window1.close();
											window.close();
										}
										if (ev.type == Event::KeyPressed)
										{
											if (ev.key.code == Keyboard::Escape)
											{
												window2.close();
												window1.close();
												window.close();
											}
										}
										bl = false;
										Ball.setPosition(640, 530);
										music.stop();
										m.play();
										window2.clear();
										window2.draw(sprite3);
										window2.draw(Gover);
										s_ins2.setPosition(-500, -110);
										window2.draw(s_ins2);
										window2.display();
									}
								}
							}
						}
						if (Ball.getPosition().x <= 30 && Ball.getPosition().y >= 300 && Ball.getPosition().y <= 560) 
						{
							c2++;
							Ball.setPosition(basex, Ball.getPosition().y);
							if (c2 == 5)
							{
								RenderWindow window3(VideoMode(1280, 720), "Hit Ball4");
								window3.setFramerateLimit(60);
								while (window3.isOpen())
								{
									Event ev1;
									while (window3.pollEvent(ev1))
									{
										if (ev1.type == Event::Closed)
										{
											window3.close();
											window1.close();
											window.close();
										}
										if (ev1.type == Event::KeyPressed)
										{
											if (ev1.key.code == Keyboard::Escape)
											{
												window3.close();
												window1.close();
												window.close();
											}
										}
										bl = false;
										Ball.setPosition(640, 530);
										music.stop();
										m.play();
										window3.clear();
										window3.draw(sprite3);
										window3.draw(Gover);
										s_ins1.setPosition(430, -90);
										window3.draw(s_ins1);
										window3.display();
									}
								}
							}
						}

						//Score
						Player1.setString(to_string(c1));
						Player1.setFont(f);
						Player1.setFillColor(Color::White);
						Player1.setPosition(560, 38);

						Player2.setString(to_string(c2));
						Player2.setFont(f);
						Player2.setPosition(650, 38);
						Player2.setFillColor(Color::White);

						//draw
						window1.clear();
						window1.draw(sprite1);
						window1.draw(s_ins2);
						window1.draw(s_ins1);
						window1.draw(Ball);
						window1.draw(TScore);
						window1.draw(Player1);
						window1.draw(Player2);
						window1.display();
					}

				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						window.close();
					}
				}
			}
			//draw
			window.clear();
			window.draw(sprite);
			window.draw(text);
			window.draw(text2);
			if ((c1 == 5|| c2 == 5) && !(event.key.code == sf::Keyboard::Escape))
			{
				music.stop();
			}
			else
			{
				music.play();
			}
			window.display();
		}
	}
	return 0;
}