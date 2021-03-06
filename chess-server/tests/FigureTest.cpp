#include <gtest/gtest.h>

#include "Figure.h"
#include "GameConstants.h"

TEST(FigureTest, create)
{
    Chess::Figure figure(0x11, "K");

    ASSERT_EQ(0x11, figure.getId());
    ASSERT_EQ("K", figure.getClassId());
}

TEST(FigureTest, row)
{
    Chess::Figure figure(0x12, "Q");
    ASSERT_EQ(0, figure.getRow());

    Chess::Figure figure1(0x12, "Q", 3);
    ASSERT_EQ(3, figure1.getRow());
}

TEST(FigureTest, setRow)
{
    Chess::Figure figure(0x12, "Q");
    ASSERT_EQ(0, figure.getRow());

    figure.setRow(5);
    ASSERT_EQ(5, figure.getRow());
}

TEST(FigureTest, column)
{
    Chess::Figure figure(0x12, "Q");
    ASSERT_EQ(0, figure.getColumn());

    Chess::Figure figure1(0x12, "Q", 3, 7);
    ASSERT_EQ(7, figure1.getColumn());
}

TEST(FigureTest, setColumn)
{
    Chess::Figure figure(0x12, "Q");
    ASSERT_EQ(0, figure.getColumn());

    figure.setColumn(5);
    ASSERT_EQ(5, figure.getColumn());
}

TEST(FigureTest, color)
{
    Chess::Figure figure(0x12, "Q");
    ASSERT_EQ(Chess::Color::White, figure.getColor());

    Chess::Figure figure1(0x13, "Q", 2, 2, Chess::Color::Black);
    ASSERT_EQ(Chess::Color::Black, figure1.getColor());
}

TEST(FigureTest, setColor)
{
    Chess::Figure figure(0x12, "Q");
    ASSERT_EQ(Chess::Color::White, figure.getColor());

    figure.setColor(Chess::Color::Black);
    ASSERT_EQ(Chess::Color::Black, figure.getColor());
}

TEST(FigureTest, write)
{
    MemoryStream stream;
    const auto& data = stream.getData();
    ASSERT_TRUE(data.empty());

    Chess::Figure figure(0x87, "ABC", 4, 6, Chess::Color::Black);
    figure.write(stream);

    std::string buffer("\x00\x87\x00\x00\x00\x01\x03\x00\x00\x00" "ABC\x00\x04\x00\x00\x00\x00\x06\x00\x00\x00\x00\x01\x00\x00\x00", 28);
    ASSERT_EQ(buffer, data);
}

TEST(FigureTest, read)
{
    std::string buffer("\x00\x87\x00\x00\x00\x01\x03\x00\x00\x00" "ABC\x00\x04\x00\x00\x00\x00\x06\x00\x00\x00\x00\x01\x00\x00\x00", 28);
    MemoryStream stream(buffer);

    Chess::Figure figure;
    figure.read(stream);

    ASSERT_EQ(0x87, figure.getId());
    ASSERT_EQ("ABC", figure.getClassId());
    ASSERT_EQ(4, figure.getRow());
    ASSERT_EQ(6, figure.getColumn());
    ASSERT_EQ(Chess::Color::Black, figure.getColor());
}
