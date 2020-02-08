#include "cynet/NetworkPackage.hpp"
#include <cstring>

namespace cyanide::cynet
{

    NetworkPackage::NetworkPackage(const Uint8& data)
    {
        setData({data});
    }

    NetworkPackage::NetworkPackage(const std::string& text)
    {
        setData({text.begin(), text.end()});
    }

    NetworkPackage::NetworkPackage(const Vector<Uint8>& data)
    {
        setData(data);
    }

    NetworkPackage& NetworkPackage::operator<<(const Uint8 data)
    {
        m_data.emplace_back(data);
        m_header.bytes += 1;
        return *this;
    }

    NetworkPackage& NetworkPackage::operator<<(const Vector<Uint8>& data)
    {
        m_data.insert(m_data.begin(), data.begin(), data.end());
        m_header.bytes += data.size();
        return *this;
    }

    NetworkPackage& NetworkPackage::operator>>(Uint8& data)
    {
        if(!m_data.empty())
        {
            data = m_data.front();
            m_data.erase(m_data.begin());
            m_header.bytes -= 1;
        }
        return *this;
    }

    NetworkPackage& NetworkPackage::operator>>(Vector<Uint8>& data)
    {
        if(!m_data.empty())
        {
            data.insert(data.begin(), m_data.begin(), m_data.end());
            m_data.clear();
            m_header.bytes = 0;
        }
        return *this;
    }

    bool NetworkPackage::empty() const
    {
        return m_data.empty();
    }

    size_t NetworkPackage::size() const
    {
        return m_data.size();
    }

    void NetworkPackage::setData(const Vector<Uint8>& data)
    {
        m_data         = data;
        m_header.bytes = m_data.size();
    }

    Vector<Uint8> NetworkPackage::getData()
    {
        return m_data;
    }

    void NetworkPackage::setHeader(const NetworkPackage::Header& header)
    {
        m_header = header;
    }

    NetworkPackage::Header NetworkPackage::getHeader() const
    {
        return m_header;
    }

}  // namespace cyanide::cynet
