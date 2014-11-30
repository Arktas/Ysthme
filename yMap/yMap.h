#ifndef YMAP_H
#define YMAP_H

#include "yMapContext.h"

class yMap
{
    public:
        yMap(unsigned int width, unsigned int height, unsigned char defaultValue = 0);
        virtual ~yMap();

        unsigned char getValue(unsigned int x, unsigned int y) const;
        void setValue(unsigned int x, unsigned int y, unsigned char value);

        const unsigned char* getValues() const{return m_data;}
        void setValues(unsigned char* data);

        unsigned int getWidth() const{return m_width;}
        unsigned int getHeight() const{return m_height;}

		void setContext(yMapContext* context){m_context = context;}
		yMapContext* getContext() const{return m_context;}

    protected:
    private:

		yMapContext* m_context;
        unsigned char* m_data;
        unsigned int m_width, m_height;
};

#endif // YMAP_H
