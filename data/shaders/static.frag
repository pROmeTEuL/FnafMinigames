uniform sampler2D texture;
uniform float u_time;
uniform vec2 u_mouse;

float random2d(vec2 coord) {
    return fract(sin(dot(coord.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

void main(void) {
    vec2 coord = gl_TexCoord[0].xy; // Normalizare coordonate
    vec4 pixelColor = texture2D(texture, coord);
    float alpha = pixelColor.a;
    if (alpha != 0.0) {
        vec3 color = vec3(0.0);
        float grain = 0.0;
        grain = random2d(sin(coord) * u_time);
        color = vec3(grain);
        gl_FragColor = vec4(color, alpha);
    } else {
        gl_FragColor = pixelColor;
    }
}
