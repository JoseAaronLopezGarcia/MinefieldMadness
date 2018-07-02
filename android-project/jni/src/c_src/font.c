#include <cbc.h>
// public globals
#include <font.h>
// private globals
const class_id font_Font__classid__ = -1787166116855805548;
//















const SDL_Color font_WHITE = {0xFF, 0xFF, 0xFF, 0x00};
const SDL_Color font_BLACK = {0};
const SDL_Color font_YELLOW = {0xFF, 0xFF, 0x00, 0x00};
const SDL_Color font_RED = {0xFF, 0x00, 0x00, 0x00};

const int font_font_sizes[5] = {16, 24, 32, 48, 64};
TTF_Font* font_fonts[5] = {NULL};
cbcstd_Semaphore fonts_sema[5];

font_Font font_Font_create(int size){
	font_Font self = (font_Font)cbcstd_alloc(sizeof(font_Font_struct));
	try{
		font_Font_init(self, size);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void font_Font_init(font_Font self, int size){
	font_Font_initsystem(self);
	font_Font_inituser(self, size);
}
void font_Font_initsystem(font_Font self){
	image_Image_initsystem((image_Image)self);
	const static class_id __classid__[4] = {
		-1787166116855805548L,
		9195669275588614450L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(font_Font_struct);
	self->render = &font_Font_render;
	self->print = &font_Font_print;
	self->__end__ = &font_Font_end;
}
void font_Font_end(font_Font self){
	font_Font_enduser(self);
	font_Font_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void font_Font_decrefs(font_Font self){
}



	
void font_Font_inituser(font_Font self, int size){
	if (size < 0 or size >= 5){
		cthrow((cbcstd_Exception)(cbcstd_SystemExit_create("ERROR: invalid font size")));
	}


	self->img_39 = NULL;

	self->size_664 = size;

	self->w_856 = size;

	self->h_856 = size;


}

void font_Font_enduser(font_Font self){
		image_Image_enduser((image_Image)self);
	return;
	
	
	


}

void font_Font_render(font_Font self, const char* text, SDL_Color color, TTF_Font* src_font){
	



	fonts_sema[self->size_664]->wait(fonts_sema[self->size_664]);
	
	if (text == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Font text is NULL\n")));
	
	}

	TTF_Font* font = src_font;
	if (font == NULL){

		font = font_fonts[self->size_664];
	
	}


	if (self->img_39 != NULL){

		SDL_DestroyTexture(self->img_39);

		self->img_39 = NULL;
	
	
	}

	SDL_Surface *surf = TTF_RenderText_Blended(font, text, color);
	if (surf == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create(SDL_GetError())));
		
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(screen_getRenderer(), surf);
	if (texture == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create(SDL_GetError())));
		
	
	}

	SDL_FreeSurface(surf);
	

	self->img_39 = texture;



	SDL_QueryTexture(self->img_39, NULL, NULL, &(self->w_856), &(self->h_856));




	fonts_sema[self->size_664]->release(fonts_sema[self->size_664]);


}

void font_Font_print(font_Font self, const char* text, int x, int y, SDL_Color color){

	self->render(self, text,  color, NULL);

	self->draw(self, x,  y);

	SDL_DestroyTexture(self->img_39);

	self->img_39 = NULL;

}


font_Font font_small_font = NULL;
font_Font font_medium_font = NULL;
font_Font font_large_font = NULL;

void font_init(){
	TTF_Init();
	
	{int i=0; for (; i<5; i++){
		fonts_sema[i] = cbcstd_Semaphore_create(1);
		font_fonts[i] = TTF_OpenFont(common_FONT, font_font_sizes[i]);
		if (font_fonts[i] == NULL){
			cthrow((cbcstd_Exception)(cbcstd_SystemError_create(SDL_GetError())));
	
		}

	}}

	font_small_font = font_Font_create(font_SIZE_SMALL);
	font_medium_font = font_Font_create(font_SIZE_MEDIUM);
	font_large_font = font_Font_create(font_SIZE_LARGE);

}

