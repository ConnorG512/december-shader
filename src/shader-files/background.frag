#version 330 core

uniform float time; // Time 

in vec2 fragmentUVCoo; // Passed in from the vertex shader.

out vec4 FragColor; // Final Colour output

void main()
{
    // Create two colours that get blended between.
    vec3 upper_sky = vec3(0.031f, 0.212f, 0.278f); 
    vec3 lower_sky = vec3(0.8f, 0.918f, 0.961f); 
    vec3 combined_sky = vec3(mix(lower_sky, upper_sky, fragmentUVCoo.y));

    FragColor = vec4(mix(lower_sky, upper_sky, fragmentUVCoo.y), 1.0f);
} 
