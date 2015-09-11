﻿precision mediump float;

uniform float uAlpha;
uniform sampler2D uTexture;
uniform bool uColorCoding;

varying vec2 vTexCoord;
varying vec4 vIdColor;


void main(void) {
	if (uColorCoding)
	{
		gl_FragColor = vIdColor;
	}
	else
	{
		vec4 pixel = texture2D(uTexture, vTexCoord);
		if (vIdColor.x < 0.0)
		{
			//is selected
			gl_FragColor = vec4(pixel.rgb, uAlpha);
		}
		else
		{
			//is not selected
			gl_FragColor = vec4(pixel.rgb * 0.7, uAlpha);
		}
	}
}