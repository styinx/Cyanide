#include "cynet/NetworkPackage.hpp"
#include <cstring>

namespace cyanide::cynet
{

    NetworkPackage& NetworkPackage::operator<<(const Uint8& data)
    {
        m_data.emplace_back(data);
        m_header.bytes = m_data.size();
        return *this;
    }

    NetworkPackage& NetworkPackage::operator<<(const Vector<Uint8>& data)
    {
        m_data.insert(m_data.begin(), data.begin(), data.end());
        m_header.bytes = m_data.size();
        return *this;
    }

    NetworkPackage& NetworkPackage::operator>>(Uint8& data)
    {
        if(!m_data.empty())
        {
            data = m_data.front();
            m_data.erase(m_data.begin());
        }
        return *this;
    }

    NetworkPackage& NetworkPackage::operator>>(Vector<Uint8>& data)
    {
        if(!m_data.empty())
        {
            data.insert(data.begin(), m_data.begin(), m_data.end());
            m_data.clear();
        }
        return *this;
    }

    size_t NetworkPackage::size()
    {
        return m_data.size();
    }

    Vector<Uint8> NetworkPackage::data()
    {
        return m_data;
    }

    NetworkPackage::Header& NetworkPackage::header()
    {
        return m_header;
    }

}  // namespace cyanide::cynet