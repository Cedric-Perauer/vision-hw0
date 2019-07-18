 #include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    if( x < 0){
        x = 0;
    }
    if( y < 0){
        y = 0;
    }
    if(x >= im.w){
  x= im.w-1;
    }
      if(y >= im.h){
  y= im.h-1;
    }
    if(c < 0){
        c = 0;

    }
    if(c > 2){
        c = 2;
    }
    return im.data[(c*im.w*im.h)+(y*im.w)+(x)];
}

 
void set_pixel(image im, int x, int y, int c, float v)
{ 
   if( x < 0){
        x = 0;
    }
    if( y < 0){
        y = 0;
    }
    if(x >= im.w){
  x= im.w-1;
    }
      if(y >= im.h){
  y= im.h-1;
    }
    if(c < 0){
        c = 0;

    }
    if(c > 2){
        c = 2;
    }
  
  im.data[(c*im.w*im.h)+(y*im.w)+(x)] = v;

}


image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    for(int i = 0; i < im.h*im.w*im.c; i++){

        copy.data[i] = im.data[i];
    }
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    for(int i = 0; i < im.h*im.w; i++){
        gray.data[i] = im.data[i] * 0.299 + im.data[i+(im.h*im.w)] * 0.587  + 0.114 * im.data[i+(2*im.h*im.w)];
    }
    return gray;
}

void shift_image(image im, int c, float v)
{
    for(int i = 0; i < im.h*im.w; i++){
        im.data[(c*im.h*im.w)+i] += v;
    }
}

void clamp_image(image im)
{ 
    for(int i = 0; i < im.c*im.h*im.w; i++){
        if(im.data[i] < 0){
            im.data[i] = 0;
        } 
        if(im.data[i] > 1){
            im.data[i] = 1;
        } 
    }
       
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
