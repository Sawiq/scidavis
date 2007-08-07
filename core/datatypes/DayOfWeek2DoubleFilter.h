/***************************************************************************
    File                 : DayOfWeek2DoubleFilter.h
    Project              : SciDAVis
    --------------------------------------------------------------------
    Copyright            : (C) 2007 by Knut Franke
    Email (use @ for *)  : knut.franke*gmx.de
    Description          : Conversion filter QDateTime -> double, translating
                           dates into days of the week (Monday -> 1).
                           
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *  This program is free software; you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation; either version 2 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the Free Software           *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor,                    *
 *   Boston, MA  02110-1301  USA                                           *
 *                                                                         *
 ***************************************************************************/
#ifndef DAY_OF_WEEK2DOUBLE_FILTER_H
#define DAY_OF_WEEK2DOUBLE_FILTER_H

#include "../AbstractSimpleFilter.h"
#include <QDateTime>

//! Conversion filter QDateTime -> double, translating dates into days of the week (Monday -> 1).
class DayOfWeek2DoubleFilter : public AbstractSimpleFilter<double>
{
	Q_OBJECT

	public:
		virtual double valueAt(int row) const {
			if (!d_inputs.value(0)) return 0;
			return double(dateTimeInput()->dateAt(row).dayOfWeek());
			/*
			QDateTime input_value = dateTimeInput()->dateTimeAt(row);
			return double(input_value.date().toJulianDay() + 1) +
				double( -input_value.time().msecsTo(QTime(12,0,0,0)) ) / 86400000.0;
			*/
		}

	protected:
		//! Using typed ports: only date-time inputs are accepted.
		virtual bool inputAcceptable(int, AbstractDataSource *source) {
			return source->inherits("AbstractDateTimeDataSource");
		}
};

#endif // ifndef DAY_OF_WEEK2DOUBLE_FILTER_H

