uniform vec2 resolution;
uniform float time;
uniform float intense;
uniform sampler2D text;
uniform float speed;
uniform vec2 graininess;

const float offset = 20.0;
const int complexity = 38;
const float Pi = 3.14159;

void main()
{
    vec2 coord = gl_TexCoord[0].xy; // Normalizare coordonate
    vec4 pixelColor = texture2D(text, coord);
    float alpha = pixelColor.a;
    if (alpha != 0.0) {
        vec2 p=(2.0*gl_FragCoord.xy-resolution)/max(resolution.x,resolution.y);
        for(int i=1;i<complexity;i++)
        {
            vec2 newp=p;
            newp.x+=graininess.x/float(i)*sin(float(i)*p.y+time/speed+0.3*float(i))+offset;
            newp.y+=graininess.y/float(i)*sin(float(i)*p.x+time/speed+0.3*float(i+100))+offset;
            p=newp;
        }
        vec3 col=vec3(intense*sin(3.0*p.x)+intense,intense*sin(3.0*p.y)+intense,intense*sin(p.x+p.y)+intense);
        col.g = col.r;
        //	col.b = col.r;
        gl_FragColor=vec4(col, 1.0);
    }
}
