#version 330 core

out vec4 FragColor;
uniform float time; // Time 

void main()
{
    float red = sin(time + 0.0) * 0.5 + 0.5;
    float green = sin(time + 2.0) * 0.5 + 0.5;
    float blue = sin(time + 4.0) * 0.5 + 0.5;

    FragColor = vec4(red, green, blue, 1.0f);
} 
