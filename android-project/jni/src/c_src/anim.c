#include <cbc.h>
// public globals
#include <anim.h>
// private globals
const class_id anim_AnimatedText__classid__ = -1249396964866377955;
//






TTF_Font* anim_font;

anim_AnimatedText anim_AnimatedText_create(char* text){
	anim_AnimatedText self = (anim_AnimatedText)cbcstd_alloc(sizeof(anim_AnimatedText_struct));
	try{
		anim_AnimatedText_init(self, text);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void anim_AnimatedText_init(anim_AnimatedText self, char* text){
	anim_AnimatedText_initsystem(self);
	anim_AnimatedText_inituser(self, text);
}
void anim_AnimatedText_initsystem(anim_AnimatedText self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-1249396964866377955L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(anim_AnimatedText_struct);
	self->draw = &anim_AnimatedText_draw;
	self->render = &anim_AnimatedText_render;
	self->__end__ = &anim_AnimatedText_end;
}
void anim_AnimatedText_enduser(anim_AnimatedText self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void anim_AnimatedText_end(anim_AnimatedText self){
	anim_AnimatedText_enduser(self);
	anim_AnimatedText_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void anim_AnimatedText_decrefs(anim_AnimatedText self){
}














void anim_AnimatedText_inituser(anim_AnimatedText self, char* text){

	self->text_393 = text;

	self->step_274 = 0.2f;

	self->amplitude_402 = 10;

	self->slope_449 = 20;

	self->angle_557 = 0.0f;

	self->offx_3 = 0;

	self->offy_400 = 0;

	self->width_105 = 0;

	self->text_len_550 = strlen(text);


	self->fonts_830 = CBC_NEW(font_Font, self->text_len_550);

	self->rendered_164 = false;

	{int i=0; for (; i<self->text_len_550; i++){

		self->fonts_830[i] = font_Font_create(font_SIZE_HUGE);

		self->render(self, i);
		font_Font tmp_olBJ_1098 = self->fonts_830[i];


		self->width_105 += tmp_olBJ_1098->getWidth(tmp_olBJ_1098);
	}}



	self->offx_3 = ((common_FLOOR_WIDTH*DIM_X)-self->width_105)/2;
	font_Font tmp_AJOM_1103 = self->fonts_830[0];


	self->offy_400 = ((common_FLOOR_HEIGHT)-tmp_AJOM_1103->getHeight(tmp_AJOM_1103))/2;


}

void anim_AnimatedText_draw(anim_AnimatedText self){

	int x = self->offx_3;

	{int i=0; for (; i<self->text_len_550; i++){




		int y = self->offy_400 + self->amplitude_402*sin(self->angle_557 + self->slope_449*i);

		if (not self->rendered_164){

			self->render(self, i);
		}

		font_Font tmp_oSkZ_1114 = self->fonts_830[i];

		tmp_oSkZ_1114->draw(tmp_oSkZ_1114, x,  y);
		font_Font tmp_8Jd5_1116 = self->fonts_830[i];

		x += tmp_8Jd5_1116->getWidth(tmp_8Jd5_1116);
	}}



	self->angle_557 += self->step_274;

	self->rendered_164 = true;


}

void anim_AnimatedText_render(anim_AnimatedText self, int i){
	char chr[2];

	chr[0] = self->text_393[i];
	chr[1] = 0;
	font_Font tmp_0Kff_1122 = self->fonts_830[i];

	tmp_0Kff_1122->render(tmp_0Kff_1122, chr,  font_RED,  anim_font);


}


void anim_init(){
	anim_font = TTF_OpenFont(common_ANIM_FONT, font_font_sizes[font_SIZE_HUGE]);

}

