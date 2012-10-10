// Auto generated by convert.sh in shaders folder
#define common_position_texture_color_vsh " \
	attribute vec4 a_position;\n \
	attribute vec2 a_texCoord;\n \
	attribute vec4 a_color;\n \
	\n \
	uniform	mat4 u_MVPMatrix;\n \
	\n \
	#ifdef GL_ES\n \
		varying lowp vec4 v_fragmentColor;\n \
		varying mediump vec2 v_texCoord;\n \
	#else\n \
		varying vec4 v_fragmentColor;\n \
		varying vec2 v_texCoord;\n \
	#endif\n \
	\n \
	void main() {\n \
	    gl_Position = u_MVPMatrix * a_position;\n \
		v_fragmentColor = a_color;\n \
		v_texCoord = a_texCoord;\n \
	}"