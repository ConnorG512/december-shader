#version 330 core

uniform float time; // Time 

in vec2 fragmentUVCoo; // Passed in from the vertex shader.

out vec4 FragColor; // Final Colour output

void main()
{
    // Sky gradiant colours
    vec3 sky_top_colour = vec3(0.2, 0.247, 0.329);
    vec3 sky_bottom_colour = vec3(0.51, 0.714, 0.82);

    FragColor = vec4(mix(sky_bottom_colour, sky_top_colour, fragmentUVCoo.y), 1.0);
} 
