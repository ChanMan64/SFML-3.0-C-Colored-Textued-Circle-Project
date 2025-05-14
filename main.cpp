#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    // Creates the window named "window", (titled "My window" on the actual window)
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    // Creates the circle shape named "shape"
    sf::CircleShape shape(200);

    // Function that sets the fill color of "shape" to a bright green color
    shape.setFillColor(sf::Color(100, 250, 50));

    // All of this deals with the texture image file
    sf::Texture texture; //Creates a texture named "texture"
    if (!texture.loadFromFile("wood_texture.png")) { // If statement to load texture from file 
        return -1;                                   // or end program if it fails to load
    }                                       // Replace "wood_texture.png" with your file name
    shape.setTexture(&texture); // Sets the texture of shape to the texture variable named "texture"
    shape.setTextureRect(sf::IntRect({80, 80}, {400, 400})); /* Sets a rectangular portion of the texture applied to 
    shape as the used portion of the texture. There first two values {80 ,80} represent the pixel location of (80, 80) and
    will be used for the top left corner of the rectangle. The {400, 400} represent the wdith and height of the rectangle.
    This function is not always necessary, but is useful if you only want to use a portion of a texture file */

    // while loop that runs while the window is open
    while (window.isOpen()) {
        // while loop to check for every user input and set it as event
        while (std::optional<sf::Event> event = window.pollEvent()) {
            // If statement that checks if the user pressed the window close button
            if(event->is<sf::Event::Closed>()) {
                window.close(); // Closes the window
            }
        }
        // Inside the scope of the while loop! 
        /* These three functions back to back 
        are the building blocks of displaying 
        frames to your window in sfml */
        window.clear(sf::Color::Black); // Clears the window with a black background color
        window.draw(shape); // Draws the shape named "shape", that we created earlier, to the window
        window.display(); // Displays the contents of the window on the screen.
    }

}
