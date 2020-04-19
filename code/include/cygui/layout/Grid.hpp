#ifndef CYANIDE_GRID_HPP
#define CYANIDE_GRID_HPP

#include "cygui/layout/ILayout.hpp"

namespace cyanide::cygui
{

    class Grid
        : public ILayout
        , public Object
    // TODO, public GridStyle
    {
    private:
        Uint8 m_cols = 0;
        Uint8 m_rows = 0;

        Uint8 m_col_max = 0;
        Uint8 m_row_max = 0;

        const Uint8 MAX_COLS = 0xFF;
        const Uint8 MAX_ROWS = 0xFF;

        Map<Uint16, ObjectSPtr> m_children;

        void updateChildrenIndices(const Uint8 new_cols);

    public:
        Grid() = default;
        explicit Grid(const Uint8 cols, const Uint8 rows);
        virtual ~Grid() = default;

        virtual void   addCol();
        virtual void   addCols(const Uint8 cols);
        virtual void   addRow();
        virtual void   addRows(const Uint8 rows);
        virtual void   addCapacity(const Uint8 cols, const Uint8 rows);
        virtual Uint16 capacity() const;
        virtual bool   add(const ObjectSPtr& object, const Uint8 col, const Uint8 row);

        /*
         * Inherited from ILayout
         */
        virtual void   calculateChildren() override;
        virtual bool   empty() const override;
        virtual size_t size() const override;
        virtual bool   add(const ObjectSPtr& object) override;
        virtual bool   insert(const ObjectSPtr& object, const int index) override;
        virtual bool   remove(const int index) override;
        virtual bool   erase(const ObjectSPtr& object) override;

        /*
         * Inherited from Object
         */
        virtual void draw() override;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_GRID_HPP
