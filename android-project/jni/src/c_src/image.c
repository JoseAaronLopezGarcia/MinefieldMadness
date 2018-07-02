#include <cbc.h>
// public globals
#include <image.h>
// private globals
const class_id image_Image__classid__ = 9195669275588614450;
//




image_Image image_Image_create(const char* path){
	image_Image self = (image_Image)cbcstd_alloc(sizeof(image_Image_struct));
	try{
		image_Image_init(self, path);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void image_Image_init(image_Image self, const char* path){
	image_Image_initsystem(self);
	image_Image_inituser(self, path);
}
void image_Image_initsystem(image_Image self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		9195669275588614450L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(image_Image_struct);
	self->loadTexture = &image_Image_loadTexture;
	self->drawClippedScaled = &image_Image_drawClippedScaled;
	self->drawClipped = &image_Image_drawClipped;
	self->drawScaled = &image_Image_drawScaled;
	self->draw = &image_Image_draw;
	self->getWidth = &image_Image_getWidth;
	self->getHeight = &image_Image_getHeight;
	self->reloadTexture = &image_Image_reloadTexture;
	self->__end__ = &image_Image_end;
}
void image_Image_end(image_Image self){
	image_Image_enduser(self);
	image_Image_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void image_Image_decrefs(image_Image self){
}





	
void image_Image_inituser(image_Image self, const char* path){

	self->path_687 = cbcstd_String_create(path);

	self->loadTexture(self);
	



	if (SDL_QueryTexture(self->img_39, NULL, NULL, &(self->w_856), &(self->h_856))){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create(SDL_GetError())));

	}


}

void image_Image_loadTexture(image_Image self){
	cbcstd_String tmp_drt6_5 = self->path_687;


	self->img_39 = IMG_LoadTexture(screen_getRenderer(), tmp_drt6_5->c_str(tmp_drt6_5));

	if (self->img_39 == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create(SDL_GetError())));
	}


	SDL_SetTextureBlendMode(self->img_39, SDL_BLENDMODE_BLEND);
	

}

void image_Image_enduser(image_Image self){
		cbcstd_Object_enduser((cbcstd_Object)self);

	SDL_DestroyTexture(self->img_39);


}

void image_Image_drawClippedScaled(image_Image self, int x, int y, int w, int h, SDL_Rect* src_rect){
	SDL_Rect info;
	info.x = x;
	info.y = y;
	info.w = w;
	info.h = h;

	if (SDL_RenderCopy(screen_getRenderer(), self->img_39, src_rect, &info)){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create(SDL_GetError())));
	}


}

void image_Image_drawClipped(image_Image self, int x, int y, SDL_Rect* src_rect){



	self->drawClippedScaled(self, x,  y,  self->w_856,  self->h_856,  src_rect);


}

void image_Image_drawScaled(image_Image self, int x, int y, int w, int h){

	self->drawClippedScaled(self, x,  y,  w,  h,  NULL);

}

void image_Image_draw(image_Image self, int x, int y){



	self->drawClippedScaled(self, x,  y,  self->w_856,  self->h_856,  NULL);


}

int image_Image_getWidth(image_Image self){

	return self->w_856;


}

int image_Image_getHeight(image_Image self){

	return self->h_856;


}

void image_Image_reloadTexture(image_Image self){
	logprint("destroying texture\n");

	SDL_DestroyTexture(self->img_39);

	self->img_39 = NULL;
	logprint("loading texture\n");

	self->loadTexture(self);

}


void image_init(){
	return;
}
