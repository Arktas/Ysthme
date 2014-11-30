#ifndef YMAPCONTEXT_H
#define YMAPCONTEXT_H

#include <vector>

class yMapContext
{
    public:

        struct yTileLink
        {
            unsigned char ID;
            int x1;
            int y1;
            int x2;
            int y2;
        };

        yMapContext();
        virtual ~yMapContext();

        void clear();

        unsigned int getTileLinkCount() const{return m_tileLinks.size();}
        void addLink(yTileLink tileLink);
        const yTileLink* getTileLink(unsigned char ID) const;

        void setTileset(const char* tilesetFilename);
        const char* getTilesetFilename() const{return m_tilesetFilename;}

    protected:
    private:

        std::vector<yTileLink> m_tileLinks;
        char m_tilesetFilename[512];
};

#endif // YMAPCONTEXT_H
