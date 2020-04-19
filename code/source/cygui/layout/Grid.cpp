#include "cygui/layout/Grid.hpp"

namespace cyanide::cygui
{

    Grid::Grid(const Uint8 cols, const Uint8 rows)
        : m_cols(cols)
        , m_rows(rows)
    {
    }

    // Private

    void Grid::updateChildrenIndices(const Uint8 new_cols)
    {
        Map<Uint16, ObjectSPtr> updated_children;
        const Uint8             old_cols = m_cols - new_cols;

        for(const auto& c : m_children)
        {
            const Uint16 old_index = c.first;
            const Uint8  old_col   = old_index / old_cols;
            const Uint8  old_row   = old_index % old_cols;

            const Uint16 new_index      = old_row * m_rows + old_col;
            updated_children[new_index] = c.second;
        }
        m_children = updated_children;
    }

    // Public

    void Grid::addCol()
    {
        ++m_cols;
        updateChildrenIndices(1);
    }

    void Grid::addCols(const Uint8 cols)
    {
        m_cols += cols;
        updateChildrenIndices(cols);
    }

    void Grid::addRow()
    {
        ++m_rows;
    }

    void Grid::addRows(const Uint8 rows)
    {
        m_rows += rows;
    }

    void Grid::addCapacity(const Uint8 cols, const Uint8 rows)
    {
        m_cols += cols;
        m_rows += rows;
        updateChildrenIndices(cols);
    }

    Uint16 Grid::capacity() const
    {
        return m_cols * m_rows;
    }

    void Grid::calculateChildren()
    {
        auto size = m_size;
        size.div(m_cols, m_rows);

        for(auto& c : m_children)
        {
            const Uint8 col = c.first / m_cols;
            const Uint8 row = c.first % m_cols;
            auto        pos = m_position;
            pos.add(col * size.width, row * size.height);
            c.second->setDimension({pos, size});
        }
    }

    bool Grid::empty() const
    {
        return m_children.empty();
    }

    size_t Grid::size() const
    {
        return m_children.size();
    }

    bool Grid::add(const ObjectSPtr& object)
    {
        if(size() >= capacity())
        {
            // If the grid is full grow into y direction.
            addRow();
        }

        return add(object, m_col_max, m_row_max);
    }

    bool Grid::add(const ObjectSPtr& object, const Uint8 col, const Uint8 row)
    {
        m_children[row * m_cols + col] = object;
        return true;
    }

    bool Grid::insert(const ObjectSPtr& object, const int index)
    {
        const Sint16 limit = std::min<Sint16>(index, MAX_COLS * MAX_ROWS);
        if(limit > capacity())
        {
            // TODO
            const Uint8 row = limit / m_cols;  // We want integer division
            const Uint8 col = limit % m_cols;
            return add(object, col, row);
        }
        m_children[limit] = object;
        return true;
    }

    bool Grid::remove(const int index)
    {
        return false;
    }

    bool Grid::erase(const ObjectSPtr& object)
    {
        return false;
    }

    void Grid::draw()
    {
        calculateChildren();

        for(const auto& c : m_children)
        {
            c.second->draw();
        }
    }

}  // namespace cyanide::cygui
